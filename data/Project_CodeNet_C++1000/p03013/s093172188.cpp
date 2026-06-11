#include <bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(),(obj).end()
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
#define PI 3.14159265358979323846264338327950L

int main() {
  	ll n,m;	
  	cin>>n>>m;
  
  	vector<ll> unsafe(n+1,0);
  for(ll i=0;i<m;i++){
    		ll a;
    		cin>>a;
             unsafe[a]++;
            }
  	  
	vector<ll> dp(n+1,0);  
  dp[0]=1;
  
  if(unsafe[1]<1){
  	dp[1]=1;}
    else{
    dp[1]=0;
    }
  
  for(ll i=2;i<n+1;i++){
  	if(unsafe[i-1]<1){
    	dp[i]+=dp[i-1];
    }
    
    if(unsafe[i-2]<1){
    	dp[i]+=dp[i-2];
    }
    
    dp[i]%=1000000007;
    
  }
  
  cout<<dp[n]<<endl;
  return 0;
  



}