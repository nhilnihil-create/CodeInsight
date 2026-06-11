#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pr;
typedef vector<pr> vp;
typedef vector<vp> vpp;
typedef vector<vector<ll> > graph;
#define pb push_back
#define mp make_pair
#define endl '\n'
void set_val(vector<ll>& v, ll val){for(ll i=0;i<v.size();i++) v[i]=val;}

ll mod = pow(10,9) + 7;
ll modulo = 998244353;
double pi = 3.141592653589793238;
ll i_mov[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll j_mov[8] = {1, 1, 1, 0, -1, -1, -1, 0};


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
    cout<<fixed;
    cout<<setprecision(10);
    ll n, m;
    cin>>n>>m;
    vector<ll> a(n);
    ll g = a[0];
    int count = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]/=2;
        if(a[i]&1 == 1)
        count++;
        
    }
    ll l = a[0];
    for(int i=1;i<n;i++)
    {
        g = __gcd(l, a[i]);
        l = (l*a[i])/g;
        // cout<<g<<" "<<l<<endl;
        if(l>m)
        {
            l = -1;
            break;
        }
    }
    // cout<<l<<endl;
    if(l==-1)
        cout<<0;
    else if(count == n)
    cout<< (m/l + 1)/2;
    else if(count == 0)
    {
      for(int i=0;i<n;i++)
      {
        if((l/a[i])%2 == 0)
        {
          l = -1;
          break;
        }
      }
      if(l==-1)
        cout<<0;
      else
        cout<< (m/l + 1)/2;        
    }
    else
    cout<<0;
    
    
    
} 