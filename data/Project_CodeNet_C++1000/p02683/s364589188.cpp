#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'
 
int main()
{
    fastio;
    lli n,m,x;
    cin>>n>>m>>x;

    vlli cost(n);

    lli val[n][m];

    rep(i,n,0){
        cin>>cost[i];

        rep(j,m,0)cin>>val[i][j];
    }

    lli ans = LLONG_MAX/2;

    for(int i = 0;i < (1LL << n);i ++){
        vlli tot(m,0);
        lli cur = 0;


        for(int j = 0;j < n;j++){
            if((i&(1<<j) )== 0)continue;

            cur += cost[j];

            for(int k = 0;k < m;k++){
                tot[k] += val[j][k];
            }
        }

        int f = 1;

        rep(j,m,0)f &= (tot[j] >= x);

        // cout<<i<<" "<<cur<<endl;

        if(f)ans=min(ans,cur);
    }
    if(ans == LLONG_MAX/2)cout<<-1<<endl;
    else cout<<ans<<endl;
}
