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

ll RepSq(ll a,ll n,ll mod){
  if(n==0){
    return 1;
  }else if(n%2!=0){
    return (a*RepSq(a,n-1,mod))%mod;
  }else{
    ll x=RepSq(a,n/2,mod);
    return (x*x)%mod;
  }
}

int main(){
  ll n; cin>>n;
  ll mod=1000000007;
  cout<<(RepSq(10,n,mod)+RepSq(8,n,mod)+2*(mod-RepSq(9,n,mod)))%mod;
}
