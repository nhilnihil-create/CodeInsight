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
const ll mx=1e6;
const ll mod=1e9+7;
bool p[mx+5];
vector<int>prime;
void seive()
{
    int i,j;
    p[0]=p[1]=true;
    for(i=4; i<=mx; i+=2)p[i]=true;
    for(i=3; i*i<=mx; i+=2)
    {
        if(!p[i])
        {
            for(j=i*i; j<=mx; j=j+2*i)
            {
                p[j]=true;
            }
        }
    }
    prime.pb(2);
    for(i=3; i<=mx; i++)
    {
        if(!p[i])prime.pb(i);
    }
}
int main()
{
    seive();
    ll n,i,ans=0;
    cin >> n;
    map<ll,int>m;
    while(n>1)
    {
        set<ll>s;
        for(i=1; i*i<=n; i++)
        {
            if(n%i==0)
            {
                s.insert(i);
                s.insert((n/i));
            }
        }
        ll z=-1;
        for(auto x: s)
        {
            if(m[x]!=0)continue;
            ll now=x;
            int coun=0;
            for(i=0; i<prime.size(); i++)
            {
                if(prime[i]>x)break;
                if(x%prime[i]==0)
                {
                    coun++;
                    if(coun>1)break;
                    while(x%prime[i]==0)x/=prime[i];
                }
            }
            if(x>1)coun++;
            if(coun==1)
            {
                z=now;
                break;
            }
        }

        if(z==-1)break;
        m[z]=1;
        n/=z;
        ans++;
    }
    cout << ans << endl;

    return 0;
}


