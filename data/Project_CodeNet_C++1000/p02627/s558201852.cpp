#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 998244353LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  char c;
  cin>>c;
  if(c-'a'<26&&c-'a'>=0) cout<<'a'<<endl;
  else cout<<'A'<<endl;
}