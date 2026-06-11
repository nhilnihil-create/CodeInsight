/// Code By t_bone_289 (Tushar Singh)
/// An Immature Programmer.... I'm still developing !!
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define endl '\n'
#define M 1000000007
#define error(x) cout << #x << " = " << x << endl;
#define pi 3.14159265358979323846
typedef long long ll;
typedef long double ld;
template <typename T>
void ContainerError(T &v){cout<<"{";for(auto &x:v){cout<<x<<',';}cout<<"}"<<endl;return;}
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll powmod(ll base,ll exp,ll MOD){ll res=1;while(exp>0){if(exp%2==1) res=(res*base)%MOD;base=(base*base)%MOD;exp/=2;}return (res%MOD);}
ll mpow(ll base,ll exp){ll res=1;while(exp>0){if(exp%2==1) res=(res*base);base=(base*base);exp/=2;}return (res);}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> v(n);
    map<ll,ll> m;
    for(auto &x:v)
    {
        cin>>x;
        m[x]++;
    }
    vector<ll> pre;
    for(auto &x:m)
    {
        pre.pb(x.se);
    }
//    ContainerError(pre);
    sort(pre.begin(),pre.end());
    ll N = pre.size();
    vector<ll> pre2(N,0);
    pre2[0] = pre[0];
    for(ll i=1;i<N;i++)
    {
        pre2[i] = pre2[i-1] + pre[i];
    }
    cout<<n<<endl;
    for(ll k=2;k<=n;k++)
    {
        ll be = 1;
        ll op = 0;
        ll en = n;
        if(N<k)
        {
            cout<<0<<endl;
            continue;
        }
        while(be<=en)
        {
            ll mid = (be+en)/2;
            ll in = N;
            ll start = 0;
            ll end = N-1;
            while(start<=end)
            {
                ll Mid = (start+end)/2;
                if(pre[Mid]>=mid)
                {
                    in = Mid;
                    end = Mid-1;
                }
                else
                {
                    start = Mid+1;
                }
            }
            ll z = N-in;
            z += (pre2[in-1]/mid);
            if(z >= k)
            {
                be = mid+1;
                op = mid;
            }
            else
            {
                en = mid-1;
            }
        }
        cout<<op<<endl;
    }
    return 0;
}





























