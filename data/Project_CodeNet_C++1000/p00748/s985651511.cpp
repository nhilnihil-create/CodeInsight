 
#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using vs=vector<string>;
using msi=map<string,int>;
using mii=map<int,int>;
using pii=pair<int,int>;
using vlai=valarray<int>;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
constexpr int gcd(int a,int b){return b?gcd(b,a%b):a;}
constexpr int lcm(int a,int b){return a*b/gcd(a,b);}

int main(){
	int n;
	vi dp(1000001,0);
	vi dp2(1000001,0);
	iota(all(dp),0);
	iota(all(dp2),0);
	for(int i=2;(i*(i+1)*(i+2)/6)<=1000000;i++){
	    int seisimentai=(i*(i+1)*(i+2)/6);
	    for(int j=0;j+seisimentai<=1000000;j++){
	        dp[j+seisimentai]=min(dp[j+seisimentai], dp[j]+1);
	    }
	    if(seisimentai%2==0)continue;
	    for(int j=0;j+seisimentai<=1000000;j++){
	        dp2[j+seisimentai]=min(dp2[j+seisimentai], dp2[j]+1);
	    }
	}
	
	
	while(cin>>n,n){
        cout<<dp[n]<<" "<<dp2[n]<<endl;
	}
	return 0;
}