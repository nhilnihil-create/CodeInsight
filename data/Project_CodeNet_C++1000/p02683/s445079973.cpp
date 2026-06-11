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
const ll mx=1e3;
const ll mod=1e9+7;
int cost[15],arr[15][15];
int n,m,x;
int ans=inf;
void rec(int ind,int co,vector<int>v)
{
    int p=0,i;
    for(i=0;i<m;i++)
    {
        if(v[i]<x)
        {
            p=1;
            break;
        }
    }
    if(!p)
    {
        ans=min(ans,co);
        return;
    }
    if(ind>n)
        return;
    rec(ind+1,co,v);
    for(i=0;i<m;i++)
    {
       v[i]+=arr[ind][i];
    }
    rec(ind+1,co+cost[ind],v);
}
int main()
{
    int i,j,c;
    cin >> n >> m >> x;
    i=1;
    int no=n;
    while(no--)
    {
       cin >> c;
       cost[i]=c;
       for(j=0;j<m;j++)
       {
           cin >> arr[i][j];
       }
       i++;
    }
    vector<int>now;
    for(i=0;i<m;i++)now.pb(0);
    rec(1,0,now);
    if(ans==inf)cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}


