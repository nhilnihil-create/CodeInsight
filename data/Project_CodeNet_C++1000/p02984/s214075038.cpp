#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
int main(){
  int n;
  cin >> n;
  vector<ll>v(n);
  rep(i,n)cin >> v[i];
  rep(i,n)v[i] *= 2;
  ll tmp = 0;
  rep(i,n)tmp = v[i] - tmp;
  ll ans = tmp / 2;
  rep(i,n){
    cout << ans << " ";
    ans = v[i] - ans;
  }
  cout << endl;
  return 0;
}