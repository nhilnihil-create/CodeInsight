#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pr;
typedef vector<pr> vp;
typedef vector<vp> vpp;
typedef vector<vector<ll> > graph;
#define pb push_back
#define mp make_pair
#define maxi INT_MAX
#define mini INT_MIN
#define endl '\n'
void set_val(vector<ll>& v, ll val){for(ll i=0;i<v.size();i++) v[i]=val;}

ll mod = pow(10,9) + 7;
ll modulo = 998244353;
ll i_mov[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll j_mov[8] = {1, 1, 1, 0, -1, -1, -1, 0};

vector<vector<int>> g;
vector<int> parent, depth, subsize;

ll power(ll a, ll n)
{
    if(n==0)
    return 1;
    ll temp = power(a,n/2);
    if(n%2==0)
    return (temp*temp)%mod;
    return (((temp*temp)%mod)*a)%mod;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout<<fixed;
    // cout<<setprecision(18);
    ll n, k;
    cin>>n>> k;
    vector<ll> count(k+1,0);
    ll ans = 0;
    for(int i=k;i>0;i--)
    {
        ll t = floor(k/i);
        ll temp = power(t,n);
        for(int j=2*i; j<=k; j+=i)
        temp=(temp-count[j])%mod;
        count[i]=temp;
    }
    for(int i=1;i<=k;i++)ans= (ans+(i*count[i])%mod)%mod;
    cout<<ans<<endl;
    
    
    
    
} 