#include<bits/stdc++.h>
#define fastAF ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define pb push_back
#define pf push_front
#define dll deque<ll>
#define vll vector<ll>
#define pll pair<ll,ll>
#define mapll map<ll,ll>
#define endl "\n"
#define all(v) v.begin(),v.end()
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
void swap(auto*,auto*);
const ll N=5e5;
vll adj[N+1]; bool visited[N+1]; ll c[N+1];
vll bfs(ll node)
{
    visited[node]=1;
    queue<ll> q; q.push(node); vll ans;
    while(!q.empty())
    {
        node=q.front(); q.pop();
        ans.pb(c[node]);
        for(ll x:adj[node])
        {
            if(visited[x]) continue;
            visited[x]=1; q.push(x);
        }
    }
    return ans;
}
int32_t main()
{
    fastAF
    ll n,k; cin>>n>>k;
    ll p[n+1]; for(ll i=1;i<=n;i++) cin>>p[i];
    for(ll i=1;i<=n;i++) cin>>c[i];
    for(ll i=1;i<=n;i++)
    {
        adj[i].pb(p[i]);
    }
    vll valArr[n+1];
    for(ll i=1;i<=n;i++)
    {
        ms(visited,0);
        valArr[i]=bfs(i);
    }
    ll sum[n+1]; ms(sum,0);
    for(ll i=1;i<=n;i++) for(ll x:valArr[i]) sum[i]+=x; 
    ll maxScore=INT_MIN;
    for(ll i=1;i<=n;i++)
    {
        ll preSum=0; ll c=0; ll len=valArr[i].size();
        for(ll x:valArr[i]){
            c++; preSum+=x;
            if(c>k) break;
            ll times=(k-c)/len;
            maxScore=max(maxScore,preSum+times*max((ll)0,sum[i]));
        }
    }
    cout<<maxScore<<endl;
    return 0;
}
void swap(auto &a,auto &b)
{
    auto temp=a; a=b; b=temp;
}