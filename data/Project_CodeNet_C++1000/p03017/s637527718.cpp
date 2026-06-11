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
  ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
  a--;b--;c--;d--;
  string s;cin>>s;
  bool ans=true;
  rep(i,n-1){
    if((i>a||i>b)&&(i+1<c||i+1<d)){
      if(s[i]=='#'&&s[i+1]=='#')ans=false;
    }
  }
  if(c>d){
    bool reverse=false;
    rep(i,n-2){
      if((i>=a&&i+1>=b)&&(i+1<=d)){
        if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.')reverse=true;
      }
    }
    if(reverse==false)ans=false;
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
    
  