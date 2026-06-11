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
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};
int main(){
  ll n;cin>>n;
  vl a(n);
  rep(i,n)cin>>a[i];
  set<ll>S;
  vl vec;
  map<ll,ll>M;
  rep(i,n){
    M[a[i]]++;
    if(!S.count(a[i])){
      vec.push_back(a[i]);
      S.insert(a[i]);
    }
  }
  if(vec.size()==1&&vec[0]==0){
    cout<<"Yes"<<endl;
    return 0;
  }
  if(S.size()==2&&n%3==0&&M[0]==n/3){
    cout<<"Yes"<<endl;
    return 0;
  }
  if((vec[0]^vec[1])==vec[2]&&M[vec[0]]==M[vec[1]]&&M[vec[1]]==M[vec[2]]){
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
}