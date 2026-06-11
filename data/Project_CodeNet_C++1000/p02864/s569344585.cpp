#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,s,f) for(i=s;i<f;i++)
#define print(v) for(auto &z:v) cout<<z<<' ';cout<<'\n'
#define hi cout<<'h'<<'i'<<'\n' 
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define B begin()
#define E end()
#define sz(v) (int)((v).size())
#define vi vector<int>
#define vii vector<pair<int,int>>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define clk1 clock_t start_time=clock()
#define clk2 cout<<(clock()-start_time)/(double)CLOCKS_PER_SEC
#define clean(arr) memset(arr,0,sizeof(arr))
#define mod 1000000007
#define mod2 998244353
#define space 100005
//<<fixed << setprecision(9)
ll dp[305][305];
int h[305];
int main()
{
    int n,i,j,t,p;
    boost;
    int k;
    cin>>n>>k;
    
    rep(i,0,n)cin>>h[i+1];
    rep(i,1,n+2)rep(j,0,k+1)dp[i][j]=1e15;
    rep(i,1,n+2)
    {
        rep(p,0,i)
        {
            rep(j,0,k+1)
            {
                int col=j+i-p-1;
                if(col>k)break;
                int cost;
                if(h[p]>=h[i])cost=0;
                else cost=h[i]-h[p];
                dp[i][col]=min(dp[i][col],dp[p][j]+cost);
            }
        }
    }

    ll ans=1e15;
    rep(i,0,k+1)ans=min(ans,dp[n+1][i]);
    cout<<ans;


    return 0;
}

