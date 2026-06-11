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

int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  vector<vector<pair<int,int>>> graph(n+1);
  for (int i = 0; i < n-1; i++) {
    int a, b; cin >> a >> b;
    graph[a].push_back({b,i});
    graph[b].push_back({b,i});
  }

  int K = 0;
  vector<int> ans(n-1);
  function<void(int,int)> Dfs = [&] (int node, int c) {
    int start = 1;
    for (auto& p: graph[node]) {
      int u = p.first;
      int idx = p.second;
      if (ans[idx] != 0) continue;
      if (start == c) start += 1;
      ans[idx] = start;
      Dfs(u,start);
      ++start;
    }
    K = max(K, start-1);
  };
  Dfs(1,0);
  cout << K << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}

