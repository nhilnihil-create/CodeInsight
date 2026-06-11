#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
 
typedef long long ll;
const ll MOD = 1'000'000'007;

#define PB push_back
#define MP make_pair
#define F first
#define S second

template<typename T,typename U>
bool chmax(T& max, const U& x){
	if(max<x){
		max = x;
		return true;
	}
	return false;
}

template<typename T,typename U>
bool chmin(T& min, const U& x){
	if(min>x){
		min = x;
		return true;
	}
	return false;
}


int main(){
  	string s;
  	cin >> s;
  	ll n = s.size();
  	ll dp[n][13];
  	fill(dp[0],dp[0]+n*13,0LL);
  	for(ll i=0;i<10;i++){
      	if(s[0]=='?'){
        	dp[0][i]=1;
        }
    	else if((s[0]-'0')==i){
        	dp[0][i]=1;
        }else{
        	dp[0][i]=0;
        }
    }
  	for(ll i=1;i<n;i++){
      	if(s[i]=='?'){
          	for(ll j=0;j<13;j++){
            	for(ll k=0;k<10;k++){
                	dp[i][ (j*10+k)%13 ] = (dp[i][(j*10+k)%13] + dp[i-1][j] )%MOD;
                }
            }
        }else{
            for(ll j=0;j<13;j++){
            	dp[i][ (j*10+(s[i]-'0'))%13 ]=dp[i-1][j];
            }    
        }
    }

  	cout << dp[n-1][5];
}