#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


#define int  long long
#define rep(i,begin,end) for(__typeof(end)i=(begin)-((begin)>(end));i!=(end)-((begin)>(end));i+=1-2*((begin)>(end)))
#define F first
#define S second
#define sz(x) ((int)x.size())
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define pf push_front
#define eb emplace_back 
#define all(v) (v).begin(), (v).end()
#define mod 100000
#define mi multiset<int>
#define mii multiset<pii>
#define what_is(x) cerr << #x << " is " << x <<"\n";
#define sortA(v) sort(v.begin(), v.end())
#define sortD(v) sort(v.rbegin(), v.rend())
#define PI 3.14159265358979323846
#define vout(a) for(auto x:a) cout<<x<<" ";
#define INF 10000000000000000

// #define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>


// using namespace __gnu_pbds;
using namespace std;

int lcm(int a,int b) {return (a*(b/__gcd(a,b)));}

int modp(int a,int m,int n)
{
    n=n%(m-1);
    a=a%m;
    int res=1;
    while(n>0)
    {
        if(n&1) res=(res*a)%m;
        a=(a*a)%m;
        n>>=1;
    }
    return res;
}



void solve()
{
    int t,n,m,i,k,l,r,u,v,w,j,s,pos,sum=0,flag=0,count=0;
    string S,T,U;
    // int h1,m1,h2,m2;
    cin>>n>>m;
    if(n==1||m==1)
    {
        cout<<"1";
        return;
    }
    // if(n%2&&m%2)
    {
        cout<<(n*m+1)/2;
    }
}



signed main()
{
 //   #ifndef ONLINE_JUDGE 
   //    freopen("input.txt","r",stdin);
     //  freopen("output.txt","w",stdout);
   // #endif
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
        if(t)cout<<"\n";
    }
    return 0;
}
