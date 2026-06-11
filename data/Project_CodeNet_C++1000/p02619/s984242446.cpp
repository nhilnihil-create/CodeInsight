#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

constexpr int CONTEST = 26;
constexpr int D = 365;

int C[CONTEST];
int S[D + 1][CONTEST];

/////////////////////////////////////////////////////////////////////////
// TIME MANAGEMENT
/////////////////////////////////////////////////////////////////////////
const double TIME_LIMIT = 1900;
struct TimeManager {
  double lim;
  double elapsed;
  chrono::system_clock::time_point t_start;

  TimeManager () {
    t_start = chrono::system_clock::now();
    lim = TIME_LIMIT;
  }
  
  template <typename T> TimeManager (const T& t) {
    t_start = chrono::system_clock::now();
    lim = static_cast<double>(t);
  }
  
  void set_time() {
    t_start = chrono::system_clock::now();
  }
  
  void update () {
    auto t_now = chrono::system_clock::now();
    elapsed = chrono::duration_cast<chrono::milliseconds>(t_now - t_start).count();
  }
  
  bool is_timeover () {
    return elapsed > lim;
  }
  
  double passed_ratio () {
    //update();
    return elapsed / lim;
  }
  
  template <typename T> bool is_passed (const T& r) {
    double tmp = static_cast<double>(r);
    return tmp > passed_ratio();
  }
};

TimeManager t_manager;
/////////////////////////////////////////////////////////////////////////
// TIME MANAGEMENT END
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// XORSHIFT
/////////////////////////////////////////////////////////////////////////
int xorShift () {
	static unsigned long long x = 88172645463325252ULL;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	return int(x & 0x7fffffff);
}
/////////////////////////////////////////////////////////////////////////
// XORSHIFT END
/////////////////////////////////////////////////////////////////////////

int cur_score = 0, best_score = 0;
int cur_schedule[D + 1], best_schedule[D + 1];
set<int> st[CONTEST];
int last[CONTEST];

void initializer () {
  for (int i = 1; i <= D; i++) {
    int val = -1;
    int idx = -1;
    for (int j = 0; j < CONTEST; j++) {
      if (val < S[i][j]) {
        val = S[i][j];
        idx = j;
      }
    }
    cur_schedule[i] = idx;
    st[idx].insert(i);
  }
  for (int i = 0; i < CONTEST; i++) {
    st[i].insert(0);
    st[i].insert(D + 1);
  }
}

int calcScore () {
  int res = 0;
  for (int i = 0; i < CONTEST; i++) last[i] = 0;
  for (int i = 1; i <= D; i++) {
    int& col = cur_schedule[i];
    int d = i - last[col];
    res += S[i][col];
    res -= C[col] * d * (d - 1) / 2;
    last[col] = i;
  }
  for (int i = 0; i < CONTEST; i++) {
    int d = D + 1 - last[i];
    res -= C[i] * d * (d - 1) / 2;
  }
  return res;
}

int update_ = 0;
bool updateBest () {
  if (best_score > cur_score) return false;
  best_score = cur_score;
  for (int i = 1; i <= D; i++) best_schedule[i] = cur_schedule[i];
  update_++;
  return true;
}

bool updateBest (const int& at, const int& col) {
  if (best_score > cur_score) return false;
  best_score = cur_score;
  best_schedule[at] = col;
  update_++;
  return true;
}

double start_temp;
double end_temp;
int changed_ = 0;
bool SA (const int& nxt_score, const int& old_score) {
  if (old_score <= nxt_score) {
    changed_++;
    return true;
  }

  double temp = start_temp + (end_temp - start_temp) * t_manager.passed_ratio();
  double prob = exp((nxt_score - old_score) / temp);

  if (prob > (double) (xorShift() % 100) / 100) {
    changed_++;
    return true;
  }
  return false;
}

int step = 0;

void change (const int& at, const int& col) {
  int rem = cur_schedule[col];
  if (rem == col) return;
  cur_schedule[at] = col;
  st[rem].erase(at);
  st[col].insert(at);
  updateBest(at, col);
}

int tryChange (const int& at, const int& col, const int& base_score) {
  if (cur_schedule[at] == col) return false;
  int rem = cur_schedule[at];
  int res = base_score;
  //removal
  {
    res -= S[rem][at];
    auto nxt = st[rem].find(at);
    auto pre = prev(nxt);
    nxt++;
    int d = at - *pre;
    res += C[rem] * d * (d - 1) / 2;
    d = *nxt - at;
    res += C[rem] * d * (d - 1) / 2;
    d = *nxt - *pre;
    res -= C[rem] * d * (d - 1) / 2;
  }
  //adding
  {
    res += S[col][at];
    auto nxt = st[col].upper_bound(at);
    auto pre = prev(nxt);
    int d = *nxt - *pre;
    res += C[col] * d * (d - 1) / 2;
    d = at - *pre;
    res -= C[col] * d * (d - 1) / 2;
    d = *nxt - at;
    res -= C[col] * d * (d - 1) / 2;
  }
  return res;
}

int fail_ = 0;
int replace_ = 0;
bool replace () {
  step++;
  int at = xorShift() % D + 1;
  int col = xorShift() % CONTEST;
  int old_score = cur_score;
  int nxt_score = tryChange(at, col, cur_score);
  if (SA(nxt_score, old_score)) {
    replace_++;
    cur_score = nxt_score;
    change(at, col);
    return true;
  } else {
    cur_score = old_score;
    fail_++;
  }
  return false;
}

int shift_ = 0;
bool shift () {
  step++;
  int at = xorShift() % D + 1;
  int col = cur_schedule[at];
  int pre_at = *prev(st[col].find(at));
  int cnt = 0;
  for (int i = pre_at + 1; i < at && cnt < 100; i++) {
    if (cur_schedule[i] != col) {
      int old_score = cur_score;
      int nxt_score = tryChange(i, col, cur_score);
      nxt_score = tryChange(at, cur_schedule[i], nxt_score);
      if (SA(nxt_score, old_score)) {
        cur_score = nxt_score;
        change(i, col);
        change(at, cur_schedule[i]);
        shift_++;
        return true;
      } else {
        cur_score = old_score;
      }
    }
    for (int j = i + 1; j < at && cnt < 0; j++) {
      if (cur_schedule[i] != col && cur_schedule[i] != cur_schedule[j] && cur_schedule[j] != col) {
        int old_score = cur_score;
        int nxt_score = tryChange(i, col, cur_score);
        nxt_score = tryChange(j, cur_schedule[i], nxt_score);
        nxt_score = tryChange(at, cur_schedule[j], nxt_score);
        if (SA(nxt_score, old_score)) {
          cur_score = nxt_score;
          change(i, col);
          change(j, cur_schedule[i]);
          change(at, cur_schedule[j]);
          shift_++;
          return true;
        } else {
          cur_score = old_score;
        }
      }
      cnt++;
    }
  }
  return false;
}

void init () {
  int t;
  cin >> t;
  for (int i = 0; i < CONTEST; i++) cin >> C[i];
  for (int i = 1; i <= D; i++) {
    for (int j = 0; j < CONTEST; j++) {
      cin >> S[i][j];
    }
  }
}


signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  init();

  // B
  // initializer();
  for (int i = 1; i <= D; i++) {
    cin >> cur_schedule[i];
    cur_schedule[i]--;
  }
  // for (int i = 1; i <= D; i++) {
  //   cout << cur_schedule[i] << endl;
  // }
  // cout << endl;
  // cur_score = calcScore();
  // cout << cur_score << endl;
  // B
  int res = 0;
  for (int i = 1; i <= D; i++) {
    for (int j = 0; j < CONTEST; j++) {
      if (j == cur_schedule[i]) {
        res += S[i][j];
      }
      int k = 0;
      for (int l = 1; l <= i; l++) if (cur_schedule[l] == j) k = l;
      res -= C[j] * (i - k);
    }
    cout << res << endl;
  }
  // cout << res << endl;
  return 0;
}