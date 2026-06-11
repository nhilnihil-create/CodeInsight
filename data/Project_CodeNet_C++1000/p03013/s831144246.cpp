#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define mod 1000000007LL
#define nax 500009LL
#define FOR(i,n,m) for(int i = (n); i < (m); i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) v.begin(),v.end()
#define sz(v) int(v.size())
 
 
typedef long long ll;
typedef vector<int> vi; 
typedef pair<int,int> ii;
 

int main(){
	fastio;
    
	int n, m; cin>>n>>m;
	bool p[nax];
	memset(p, 0, sizeof p);
	int x;
	REP(i,m) cin>>x, p[x]=1;

	int dp[nax];

	dp[0]=1;
	if(p[1]){
		dp[1]=0;
	}
	else{
		dp[1]=1;
	}
	FOR(i,2,n+1){
		if(p[i]){
			dp[i]=0;
		}
		else{
			if(!p[i-1]){
                dp[i]+=dp[i-1];
                dp[i]=dp[i]%mod;
            }
            if(!p[i-2]){
                dp[i]+=dp[i-2];
                dp[i]=dp[i]%mod;
            }
		}
	}

    cout<<dp[n];


	return 0;
}