#include <bits/stdc++.h>
using namespace std;

using ll= long long;
#define double long double
#define sz(x) (int)x.size()
#define all(x) (x).begin(),(x).end()
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define _set(x) __builtin_popcount(x)
#define PI  3.14159265358979323846264338327950L
#define mod 1000000007
#define dpv(...) cerr<< "["#__VA_ARGS__ " : ";for(int i: (__VA_ARGS__)){cerr<<i<<" ";}cerr<<"]\n"

const int maxN= 105;
const int INF = 1e9;
int dp[maxN][maxN];
bool g[maxN][maxN];
void solve(){
    int h,w;
    cin>>h>>w;
    char c;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>c;
            g[i][j]=(c=='#')?0:1;
            dp[i][j]= INF;
        }
    }
    dp[0][0]= g[0][0]?0:1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            dp[i+1][j] = min(dp[i+1][j],(g[i][j] && !g[i+1][j])? dp[i][j]+1: dp[i][j] );
            dp[i][j+1] = min(dp[i][j+1],(g[i][j] && !g[i][j+1])? dp[i][j]+1: dp[i][j] );
        }
    }
    cout<<dp[h-1][w-1]<<"\n";
}

int32_t main(){
	IOS
	// freopen("input.txt","r",stdin);
	int _;
	// cin>>_;
	_=1;
	while(_--){
        solve();
    }
	return 0;
}

/*
   check for overflows int long long
   correct size of array
*/