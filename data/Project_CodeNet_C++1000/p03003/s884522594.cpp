// !Start && !End 
//  0 se divide
//https: //www.youtube.com/watch?v=6Nb-prB-4P0&list=RD6Nb-prB-4P0&start_radio=1

// https: //www.youtube.com/watch?v=eYDI8b5Nn5s
// Electrify my OOOoooooOOOoooOOOOOoooooOOOooo!
#pragma optimise GCC(-O2)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define ve(x) vector<x>
#define f(a,b,c) for(int a=b;a<c;a++)
#define foto(x,v) for(auto x:v)
#define read(t) ll t; cin>>t;
#define reads(t) string t; cin>>t;
#define readarr(arr,n) ll arr[n]; f(i,0,n) cin>>arr[i];
#define forstl(i,v) for(auto &i: v)
#define ln endl
#define Endl endl
#define dbg(x) cout<<#x<<" = "<<x<<ln;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<ln;
#define dbgstl(v) cout<<#v<<" = \n"; { int c=0; forstl(it,v) \
cout<<"    Term "<< ++c <<" = "<<it<<ln;} cout<<ln;
#define dbgstlp(v) cout<<#v<<" = \n"; { int c=0; forstl(it,v) \
cout<<"    Term "<< ++c <<" = "<<it.fi<<" , "<<it.se<<ln;} cout<<ln;
#define dbgarr(v,s,e) cout<<#v<<" = "; f(i,s,e) cout<<v[i]<<", "; cout<<ln;
#define addEdge(tr,k) f(i,0,k) { ll x,y; cin>>x>>y, tr[x].push_back(y), tr[y].push_back(x);}
#define all(v) v.begin(),v.end()

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }

//														GLOBAL VARS
ll INF =LLONG_MAX;
const ll M= 1000000007;

//														USEFUL FUNCTIONS
ll powm(ll ,ll);

// 														MAIN
int main()
{ 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    //It gets easier day by day, but the hard part is to........
    read(n) read(m)
    readarr(a,n) readarr(b,m)
    ll dp[n+1][m+1];
    memset(dp,0 ,sizeof(dp));
    // dp[0][0] = 1;
    // f(i,0,n) dp[i][0] = 1;
    // f(j,0,m) dp[0][j] = 1;
    f(i,0,n)
    {
        f(j,0,m)
        {
            if(a[i] == b[j])
            {
                dp[i+1][j+1] = (1 + dp[i][j+1] + dp[i+1][j])%M;
            }
            else
            {
                dp[i+1][j+1] = (dp[i][j+1] + dp[i+1][j] - dp[i][j])%M;
            }
            
        }
    }
    cout<<(dp[n][m]+1+3000*M)%M;
}










//													FUNCTIONS DECLARATIONS
ll powm(ll a, ll b) {
	ll res=1;
	while(b) {
		if(b&1)
			res=(res*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return res;
}
