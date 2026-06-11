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
    int ans = 0;
    lli n,m,k,left;
    cin>>n>>m>>k;
    vinput(a,n);
    vinput(b,m);

    rep(i,n,1){
        a[i] += a[i - 1];
    }

    rep(i,m,1){
        b[i] += b[i - 1];
    }

    rep(i,n,0){
        if(a[i] > k)break;
        left = k - a[i];

        ans = max(ans,i + 1 + (int)(upper_bound(all(b),left) - b.begin()));
    }

    rep(i,m,0){
        if(b[i] > k)break;
        left = k - b[i];

        ans = max(ans,i + 1 + (int)(upper_bound(all(a),left) - a.begin()));
    }

    cout<<ans<<endl;
}