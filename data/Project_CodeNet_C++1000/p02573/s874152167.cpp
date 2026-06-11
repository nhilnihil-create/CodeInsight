
#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
//cout << fixed << setprecision(8) << a << endl;
#define Fast_Input ios_base :: sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define pb push_back
#define mem(a, b)     memset(a, b, sizeof(a))
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
/*sort(v.begin(), v.end(),
     [](const pair<int, int>& x, const pair<int, int>& y)
{
    if (x.first != y.first)
        return x.first < y.first;
    return x.second < y.second;
});
*/
int const fx[]= {+1,+0,-1,+1};
int const fy[]= {-1,+1,+0,+0};
const int inf = numeric_limits<int>::max();
const int mx=2e5;
const ll mod=1e9+7;
int par[mx+5];
int fin(int r)
{
    if(par[r]==r)return r;
    par[r]=fin(par[r]);
    return par[r];
}
int main()
{
    int n,m,x,y,u,v,i;
    cin >> n >> m;
    for(i=1;i<=n;i++)par[i]=i;
    while(m--)
    {
        cin >> x >> y;
        u=fin(x);
        v=fin(y);
        if(u!=v)par[u]=v;
    }
    map<int,int>mp;
    int maxi=-1;
    for(i=1;i<=n;i++)
    {
        mp[fin(i)]++;
        if(mp[fin(i)]>maxi)
            maxi=mp[fin(i)];
    }
    cout << maxi << endl;
    return 0;
}


