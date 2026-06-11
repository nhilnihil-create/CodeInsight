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
    ll n;
    cin>>n;
    ll temp = n-1;
    ll ans = 1;
    for(int i=2;i<=sqrt(n-1);i++)
    {
        int count = 0;
        while(temp%i == 0)
        {
            temp/=i;
            count++;
        }
        ans*= (count+1);
    }
    if(temp>1)
    ans*=2;
    for(int i=2;i<=sqrt(n);i++)
    {
        temp = n;
        while(temp%i == 0)
        temp/=i;
        if(n%i == 0 && temp%i == 1)
        ans++;
    }
    cout<<ans<<endl;
    
}