#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define ff first
#define ss second
#define p pair<ll,ll>
#define pb push_back
#define endl '\n'
#define w(t) ll test;cin>>test;while(test--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define iof  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pi acos(-1)
const int mxn=1e9+5;
int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<int>vec(n),a(n);
    for(auto &i:vec)
    {
        cin>>i;
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        a[u]=max(a[u],vec[v]);
        a[v]=max(a[v],vec[u]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(vec[i]>a[i])ans++;
    }
    cout<<ans<<endl;
}

