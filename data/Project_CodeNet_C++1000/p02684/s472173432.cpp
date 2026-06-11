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
int main()
{
    ll n,k,i;
    cin >> n >> k;
    map<int,int>m;
    for(i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        m[i]=x;
    }
    int now=1,d=1;
    map<int,int>c;
    for(i=1;i<=n;i++)c[i]=-1;
    c[1]=0;
    int target=0,from;
    int mov=0;
    while(1)
    {
        if(now==m[now])
        {
            cout << now << endl;
            return 0;
        }
        now=m[now];
        mov++;
        if(mov==k)
        {
            cout << now << endl;
            return 0;
        }
        if(c[now]==-1)
        {
            c[now]=d;
            d++;
        }
        else
        {
            k-=c[now];
            target=k%(d-c[now]);
            from=now;
            break;
        }
    }
    //cout << target << " " << from << endl;
    now=from;
    while(target)
    {
        now=m[now];
        target--;
    }
    cout << now << endl;
    return 0;
}


