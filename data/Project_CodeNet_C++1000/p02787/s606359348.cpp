# include "bits/stdc++.h"
 
using namespace std;
 
#define endl "\n"
typedef long long int ll;
#define f first
#define s second
 
inline void fastio(){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
inline void setPrecision(int n){cout.precision(n);}
 
//DEBUG
#define dbg(x) cerr<<(#x)<<": "<<x<<endl
#define dbgV(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<it<<" "; cerr<<endl;
#define dbgS(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<it<<" "; cerr<<endl;
#define dbgM(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<"["<<it.f<<", "<<it.s<<"] "; cerr<<endl;
#define dbg2D(x) cerr<<(#x)<<": \n"; for(auto y: x) { for(auto it: y) cerr<<it<<" "; cerr<<endl; } cerr<<endl;
#define dbgA(x, n) cerr<<(#x)<<": "; for(int i=0;i<n;++i) cerr<<x[i]<<" "; cerr<<endl;
#define dbgVP(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<"["<<it.f<<", "<<it.s<<"] "; cerr<<endl;
 
ll INF = 1e10;
int MOD = 1e9+7;

int main(){
    fastio();

    int n, h;
    cin >> h >> n;

    int a[n], b[n];
    int mx = 0;
    for(int i = 0; i < n; ++i){
    	cin >> a[i] >> b[i];
    	mx = max(mx, a[i]);
    }

    vector<int> dp(h + mx + 1, 1e9);
    for(int i = h; i <= h + mx; ++i)
    	dp[i] = 0;

    for(int i = 0; i < n; ++i){
    	for(int j = h + mx; j >= 0; --j){
    		if(j + a[i] <= h + mx){
    			dp[j] = min(dp[j], b[i] + dp[j + a[i]]);
    		}
    	}
    }

    cout << dp[0];
    return 0;
}

/*

*/