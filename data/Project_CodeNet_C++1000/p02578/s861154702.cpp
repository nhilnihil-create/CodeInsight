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
const int mx=1e9;
const int mod=1e9+7;
int main()
{
    int n,i;
    cin >> n;
    vector<int>v(n);
    for(i=0;i<n;i++)cin >> v[i];
    ll prev=v[0],sum=0;
    for(i=1;i<n;i++)
    {
        if(v[i]<prev)
        {
            sum+=(prev-v[i]);
        }
        else
            prev=v[i];
    }
    cout << sum << endl;
    return 0;
}


