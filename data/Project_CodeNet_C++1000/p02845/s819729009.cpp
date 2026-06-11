#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll n;
  cin >> n;
  vl a(n);
  rep(i,n){
    cin >> a[i];
  }
  vl cnt(n,0);
  ll ans=1;
  rep(i,n){
    cnt[a[i]]++;
    if(a[i]==0){
      if(cnt[a[i]]<4){
        ans=ans*(4-cnt[a[i]])%MOD;
      }
      else{
        ans=0;
      }
    }
    else{
    if(cnt[a[i]]==3&&cnt[a[i]-1]==3){
      ans*=1;
    }
    else if(cnt[a[i]]==2&&cnt[a[i]-1]==2){
      ans*=1;
    }
    else if(cnt[a[i]]==2&&cnt[a[i]-1]==3){
      ans =ans*2%MOD;
    }
    else if(cnt[a[i]]==1&&cnt[a[i]-1]==3){
      ans =ans*3%MOD;
    }
    else if(cnt[a[i]]==1&&cnt[a[i]-1]==2){
      ans =ans*2%MOD;
    }
    else if(cnt[a[i]]==1&&cnt[a[i]-1]==1){
      ans *=1;
    }
    else ans=0;
    }
  }
  cout << ans << endl;
}