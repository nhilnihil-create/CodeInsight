#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

//j-i=a[j]+a[i]
//j-a[j]=i+a[i]
int main(){
  ll n;
  cin >> n;
  vector<ll>wa(200000),sa(200000);
  for(int i=0; i<n; i++){
    ll a;
    cin >> a;
    if(a+i+1<200000) wa[a+i+1]++;
    if(i+1-a>=0) sa[i+1-a]++;
  }
  ll ans=0;
  for(ll i=1; i<200000; i++){
    ans+=wa[i]*sa[i];
  }
  
  cout << ans << endl;
  
}
  
