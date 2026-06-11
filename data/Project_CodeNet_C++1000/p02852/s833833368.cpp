#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef unordered_set<int> si;
typedef pair<int, int> pp;
typedef vector<pp> vpp;
typedef unsigned int i64;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define bye(x) return void (cout <<(x) << endl);
#define all(e) (e).begin(), (e).end()
#define pb push_back

template <typename T>
bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}


template <typename T>
void printV(vector<T> A) {
  if (A.empty()) cerr << "EMTPY\n";
  else { 
    cerr << "[";
    for (int i = 0; i < A.size() -1 ; ++i) {
      cerr << A[i] << ", ";
    }
    if (A.size()) cerr << A.back() << "]\n";
  }
}


template <typename T>
void printVV(vector<vector<T>> A) {
  cerr << "[";
  for (auto v : A) {
    printV<T>(v);
  }
  cerr << "]";
}

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&& ...args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}


int n, m;

struct S {
  int idx;
  int cost;
  bool operator< (const struct S& other) const {
    if (cost == other.cost) return idx > other.idx;
    return cost > other.cost;
  }
};

int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  string s; cin >> s;
  ++n;


  priority_queue<S> pq;
  pq.push({0,0});

  vector<int> prev(n);
  for (int i = 1; i < n; i++) {
    if (s[i] == '1') continue;
    while (!pq.empty() && pq.top().idx < i - m) pq.pop();
    if (pq.empty()) {
      cout << -1 << endl;
      return 0;
    }
    auto s = pq.top();
    pq.push({i, s.cost + 1});
    prev[i] = s.idx;
  }
  vector<int> ans;
  int p = n - 1;
  while (p != 0) {
    int np = prev[p];
    ans.push_back(p - np);
    p = np;
  }
  reverse(ans.begin(),ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}

