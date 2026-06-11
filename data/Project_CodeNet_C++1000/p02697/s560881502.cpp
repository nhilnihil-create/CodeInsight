//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};
int main(){
  ll n,m;cin>>n>>m;
  ll count=0;
  if(n%2==1){
    while(true){
      cout<<count+1<<" "<<n-1-count<<endl;
      count++;
      if(count==m)break;
    }
    return 0;
  }
  /*while(true){
    cout<<count+1<<" "<<n-1-count<<endl;
    count++;
    if(count==m)break;
  }*/
  ll k=n/2;
  ll i=0,j=0;
  while(true){
    cout<<i+1<<" "<<k-i<<endl;
    i++;
    if(i+j==m)break;
    cout<<k+1+j<<" "<<n-j-1<<endl;
    j++;
    if(i+j==m)break;
  }
}
