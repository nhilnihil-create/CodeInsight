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

const int N = 2e5 + 10;
ll members[N], dishes[N];

int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> members[i];
  for (int i = 0; i < n; i++) cin >> dishes[i];
  sort(members,members+n);
  sort(dishes,dishes+n);
  
  ll begin = 0, end = 0;
  ll total = 0;
  for (int i = 0; i < n; i++) {
    end = max(end, members[i] * dishes[n-i-1]);
    total += members[i];
  }

  if (k == 0) {
    cout << end << endl;
    return 0;
  }

  if (k >= total) {
    cout << 0 << endl;
    return 0;
  }



  while (begin < end) {
    ll mid = begin + ((end - begin) / 2);
    bool fail = false;
    ll kk = k;
    for (int i = 0; i < n; i++) {
      ll x = members[i];
      ll y = dishes[n-i-1];
      if (x * y <= mid) continue;
      kk -= (x - mid / y);
      if (kk < 0) {
        fail = true;
        break;
      }
    }
    if (fail) begin = mid + 1;
    else end = mid;
  }


  cout << end << endl;

  return 0;
}
