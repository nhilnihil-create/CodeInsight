//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//約数の列挙O(√n)
vector<ll>divisor(ll n){
  vector<ll>res;
  for(ll i=1;i*i<=n;i++){
    if(n%i==0){
      res.push_back(i);
      if(i != n/i) res.push_back(n/i);
    }
  }
  return res;
}
int main(){
  ll n,k;cin>>n>>k;
  vl a(n);
  rep(i,n)cin>>a[i];
  ll sum=0;
  rep(i,n)sum+=a[i];
  vector<ll>vec=divisor(sum);
  sort(vec.begin(),vec.end());
  for(ll s=vec.size()-1;s>=0;s--){
    vector<ll>surplus=a;
    rep(i,n)surplus[i]%=vec[s];
    sort(surplus.begin(),surplus.end());
    ll MIN=INF;
    rep(i,n){
      ll count=0;
      ll total=0;
      rep(j,i){
        count+=surplus[j];
        total+=surplus[j];
      }
      for(ll k=i;k<n;k++){
        count+=vec[s]-surplus[k];
        total-=vec[s]-surplus[k];
      }
      count=abs(total)+(count+1)/2;
      if(count<=k){
        cout<<vec[s]<<endl;
        return 0;
      }
    }
  }
}