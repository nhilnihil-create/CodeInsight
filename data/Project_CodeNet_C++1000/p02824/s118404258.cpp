#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n, m, v, p;
  cin >> n >> m >> v >> p;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  sort(an.begin(),an.end());
  vector<ll> ep(n+1,0);
  for(int i=1; i<=n; ++i) ep[i] = ep[i-1] + an[i-1];
  
  int ans = p;
  int bord = an[n-p];
  for(int i=n-p-1; i>=0; --i){
    bool flag = (ep[n-p+1] - ep[i]) - (ll)(n-v)*m <= (ll)an[i]*(n-p-i+1);
    //cout << ep[n-p+1] - ep[i] << '-' << (n-v)*m << ':' << (ll)an[i]*(n-p-i+1) << endl;
    if(bord-an[i] <= m && flag){
      ++ans;
    }
  }
  cout << ans << endl;
}