#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int mod = 1e9+7;

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<int> que;
  rep(i,n) {
    int a; cin >> a;
    que.push(a);
  } 
  while (m--) {
    int p = que.top(); que.pop();
    p /= 2;
    que.push(p);
  }
  ll res = 0;
  while (!que.empty()) res += que.top(), que.pop();
  cout << res << endl;
  return 0; 
}
