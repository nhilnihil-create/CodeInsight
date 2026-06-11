#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){
  ll n;
  cin >>  n;
  vector<ll> a(n);
  ll ans=0;
  ll m=1000000007;
  for(ll i = 0;i<n;i++){
    cin >>  a[i];
  }
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  for(int i = 1;i<(n/2);i++){
    ans+=2*a[i];
  }
  if(n%2==1){
    ans+=a[n/2];
  }
  
  cout<<ans+a[0]<<endl;
    return 0;
}
