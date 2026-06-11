#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define endl        '\n'
#define mii         map<ll int,ll int>
#define msi         map<string,ll int>
#define mis         map<ll int, string>
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define repp(i,a,b)    for(ll int i=b-1;i>=a;i--)
#define tr(container,it) for(__typeof__(container.begin()) it = container.begin(); it != container.end(); it++)
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define mpi         map<pair<ll int,ll int>,ll int>
#define vii         vector<pair<ll,pair<ll,ll> > >
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        998244353
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define what_is(x)  cerr << #x << " is " << x << endl;
using namespace std;
#define N  300005
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";


// class MemoryGame{
// public:
// // vs construct(int n){
void solve(){
	ll n,m;
	cin>>n>>m;
	string s[n];
	rep(i,0,n) cin>>s[i];
	ll dp[n+5][m+5];
	rep(i,0,n+2)
	rep(j,0,m+2)
	dp[i][j]=0;
	if(s[0][0]=='#')
	dp[0][0]++;
	rep(i,0,n){
		rep(j,0,m){
			if(i==0&&j==0) continue;
			if(i==0){
				if(s[i][j]=='.')
					dp[i][j]=dp[i][j-1];
				if(s[i][j]=='#'){
					if(s[i][j-1]=='#')
						dp[i][j]=dp[i][j-1];
					else
						dp[i][j]=dp[i][j-1]+1;
				}
			}
			else if(j==0){
				if(s[i][j]=='.')
					dp[i][j]=dp[i-1][j];
				if(s[i][j]=='#'){
					if(s[i-1][j]=='#')
						dp[i][j]=dp[i-1][j];
					else
						dp[i][j]=dp[i-1][j]+1;
				}
			}
			else{
				if(s[i][j]=='.')
					dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
				if(s[i][j]=='#'){
					if(s[i-1][j]=='#'&&s[i][j-1]=='#')
						dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
					else if(s[i-1][j]=='#')
						dp[i][j]=min(dp[i-1][j],dp[i][j-1]+1);
					else if(s[i][j-1]=='#')
						dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]);
					else
						dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
				}	
			}
		}
	}	
	cout<<dp[n-1][m-1];
}
// };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll TESTS=1,an=1,a,b;
    // cin>>TESTS;
    while(TESTS--){
        // cout<<"Case #"<<an<<": ";
        an++;
        solve();

    }
    return 0;
}
