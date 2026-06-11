#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define ar array
#define db double
#define filename "SUBKGCD"
#define pow pw
const db pi = 3.14159265358979323846;
int pw(int a,int b){
	int ans=1;
	while(b){
	if (b%2) ans*=a;
	a*=a;
	b/=2;
	}
	return(ans);
}
const int mxn=2e5+3;
int n,q;
int p[mxn],s[mxn];
int findr(int u)
{
    while(u!=p[u]) u=p[u];
    return(u);
}
bool same(int u,int v)
{
    return(findr(u)==findr(v));
}
void combine(int u,int v)
{
    u=findr(u);
    v=findr(v);
    if (s[u]<s[v]) swap(u,v);
    p[v]=u;
    s[u]+=s[v];
}
signed main()
{
    //freopen(filename".inp","r",stdin);
    //freopen(filename".out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>q;
    for (int i=0;i<n;i++)
    {
        p[i]=i;
        s[i]=1;
    }
    while(q--)
    {
        int qu,u,v;
        cin>>qu>>u>>v;
        if (qu==1)
        {
            cout<<same(u,v)<<"\n";
        }
        else
        {
            combine(u,v);
        }
    }
	return 0;
}
