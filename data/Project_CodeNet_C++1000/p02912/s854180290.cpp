#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int mod = 1000000007;
const ll INF = 1001001001;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  int n,m;
  cin >> n >> m;
  priority_queue<int> q;
  ll ans = 0;
  rep(i,n){
    int a;
    cin >> a;
    q.push(a);
  }
  rep(i,m){
    int b = q.top();
    q.pop();
    q.push(b/2);
  }
  while(!q.empty()){
    ans += q.top(); q.pop();
  }
  cout << ans << endl;
  return 0;
  
}