//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll m,d;cin>>m>>d;
  ll count=0;
  for(ll i=1;i<=d;i++){
    ll k=i%10;
    ll j=i/10;
    if(k>=2&&j>=2&&k*j<=m)count++;
  }
  cout<<count<<endl;
}