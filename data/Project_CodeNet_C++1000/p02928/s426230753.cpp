#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

const ll MOD=1e9+7;

int main(){
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }
  ll ans=0;
  for(int i = 0; i < n; i++){
    ll big=0, small=0;
    for(int j = i+1; j < n; j++){
      if(a[i] > a[j]) small++;
      if(a[i] < a[j]) big++;
    }
    ans += big * (k*(k-1)/2 % MOD) + small * (k*(k+1)/2 % MOD);
    ans%=MOD;
  }
  cout<<ans<<endl;
}