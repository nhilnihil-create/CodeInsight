#include<iostream>
#include<cmath>
#include<numeric>
#include<functional>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define ll long long
#define INF 2147483647
using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ll mod=1000000007;
  ll n,k,ans=0; cin>>n>>k;
  ll a[n],totalsm[n]={},rightsm[n]={};
  rep(i,n){
    cin>>a[i];
  }
  rep(i,n){
    rep(j,n){
      if(a[i]>a[j]){
        totalsm[i]++;
        if(i<j){
          rightsm[i]++;
        }
      }
    }
  }
  rep(i,n){
    ll tmp=(k*(k-1)/2)%mod;
    ans+=(tmp*totalsm[i]+k*rightsm[i])%mod;
    ans%=mod;
  }
  cout<<ans;
}