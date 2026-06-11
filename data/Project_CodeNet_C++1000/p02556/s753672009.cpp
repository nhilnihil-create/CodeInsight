#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  int N;
  cin>>N;
  vector<ll> x(N),y(N);
  ll maxi(-INFll), mini(INFll);
  ll maxj(-INFll), minj(INFll);
  for(int i(0);i<N;i++){
    cin>>x[i]>>y[i];
    maxi = max(maxi, x[i]+y[i]);
    mini = min(mini, x[i]+y[i]);
    maxj = max(maxj, ll(10e9)-x[i]+y[i]);
    minj = min(minj, ll(10e9)-x[i]+y[i]);
  }
  cout << max(abs(maxi-mini),abs(maxj- minj)) << endl;
  return 0;
}

