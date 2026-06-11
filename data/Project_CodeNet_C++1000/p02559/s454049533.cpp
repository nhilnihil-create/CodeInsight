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
const int mxn=5e5+3;
int n,q;
int ft[2*mxn];
void upd(int i,int v)
{
    while(i<=n)
    {
        ft[i]+=v;
        i+=i&-i;
    }
}
int que(int i)
{
    int res=0;
    while(i>=1)
    {
        res+=ft[i];
        i-=i&-i;
    }
    return(res);
}
signed main()
{
    //freopen(filename".inp","r",stdin);
    //freopen(filename".out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        upd(i,x);
    }
    while(q--)
    {
        int qu,a,b;
        cin>>qu>>a>>b;
        if (qu==0)
        {
            upd(a+1,b);
        }
        else cout<<que(b)-que(a)<<"\n";
    }
	return 0;
}
