#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};
using Vote = pair<ll,ll>;
using Unordered_map = unordered_map<Vote, int, pair_hash>;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define showvec(arr,a,b) for(ll i=a;i<b;i++) cout<<arr[i]<<" ";
#define read_input(arr,a,b) for(ll i=a;i<b;i++) cin>>arr[i];
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
#define SmooothOperatorrrrr()                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                    \
    cout.tie(0);                   
#define deci(n) cout<<fixed<<setprecision(n)
const int mod=998244353;
const int mod2=1000000007;
#define M_PI 3.14159265358979323846
#define LL_MAX 9223372036854775807
#define MAXN 2000001
/**************************************************************************************************/
int main()
{
    SmooothOperatorrrrr();
    int n;cin>>n;
    ll l[n];
    read_input(l,0,n);
    ll count=0;
    FOR(i,0,n-2)
    {
        FOR(j,i+1,n-1)
        {
            if(l[i]!=l[j])
            {
                FOR(k,j+1,n)
                {
                    if(l[j]!=l[k]&&l[i]!=l[k])
                    {
                        vll v;
                        v.pb(l[i]);
                        v.pb(l[j]);
                        v.pb(l[k]);
                        sort(v.begin(),v.end());
                        if(v[0]+v[1]>v[2])
                            count++;
                    }
                }
            }
        }
    }
    cout<<count<<endl;
}       