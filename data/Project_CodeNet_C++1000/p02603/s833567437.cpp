//---Vaidik Patel---//
//-------------------Proud to be Indian--------------------------------//
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp> // include the associative containers or group of templates such as set,multi multimap, map etc.
#include<ext/pb_ds/tree_policy.hpp> // include the tree_order_statistics_node update
using namespace __gnu_pbds;
#define int long long int
#define ld long double
#define pii pair<int,int>
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; // find_by_order()
#define deb1(x) cout<<#x<<" : "<<x<<"\n";
#define deb2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<"\n";
#define deb3(x,y,z) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<" "<<#z<<": "<<z<<"\n";
#define deb4(x,y,z,w) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<"\t"<<#w<<" : "<<w<<endl;
#define deb5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl;
#define deb6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rFOR(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vector<int>>
#define M 1000000007
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int powermodm(int x,int n,int m)
{int ans=1;   while(n){if(n&1){ans=(ans*x)%m;}x=(x*x)%m;n=n>>1;}return ans;}

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    FOR(i,0,n)
    {
        cin>>a[i];
    }
    vi ans;
    ans.pb(a[0]);
    FOR(i,1,n-1)
    {
        if(i-1>=0 && i+1<n)
        {
            if(a[i-1]<=a[i] && a[i]>a[i+1])
            {
                ans.pb(a[i]);
            }
            else if(a[i-1]>=a[i] && a[i]<a[i+1])
            {
                ans.pb(a[i]);
            }
        }
    }
    ans.pb(a[n-1]);

    // for(auto it:ans)
    // {
    //     cout<<it<<" ";
    // }cout<<"\n";
    int curr=1000,stk=0;

    for(int i=0;i<ans.size()-1;i++)
    {
        if(ans[i]>=ans[i+1])
            continue;
        int tt=curr/ans[i];
        curr%=ans[i];
        curr+=tt*ans[i+1];
    }
    cout<<curr<<"\n";
}
signed main()
{
    
    FIO
    int t;
    t=1;
    //cin>>t;
    FOR(i,0,t)
    {
        solve();
        //cout<<"Case #"<<i+1<<": "<<ans<<"\n";
    }
}
