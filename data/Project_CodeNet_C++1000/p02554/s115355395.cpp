#include<bits/stdc++.h>

using   namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

#define  all(v)       (v).begin(),(v).end()
#define  rall(v)      (v).rbegin(),(v).rend()
#define  pb           push_back  
#define  eb           emplace_back
#define  mp           make_pair
#define  ff           first
#define  ss           second
#define  pf           push_front
#define  bs           binary_search
#define  lb           lower_bound
#define  ub           upper_bound
#define  umap         unordered_map
#define  uset         unordered_set
#define  dec(x)       fixed<<setprecision(x)
#define  lcm(a,b)    (a*b/__gcd(a,b))

typedef  priority_queue<ll>  pq;
typedef  priority_queue<ll,vector<ll>,greater<ll>> pqmn;
typedef  pair<ll,ll> pll;

const    ll inf=LLONG_MAX;
const    ll mod=1e9+7;
const    ld pi=acos(-1);

ll binpow(ll a, ll b) 
{ 
    ll ans = 1; 
    while (b) { 
        if (b & 1) 
            ans = ans * a % mod; 
        a= a * a % mod; 
             b >>=1;
    } 
    return ans%mod; 
} 
                    
void solution(){
    ll n;
    cin>>n;
    ll val=((binpow(10,n)%mod)-(binpow(9,n)%mod)-(binpow(9,n)%mod)+(binpow(8,n)%mod))%mod;
    cout<<(val+mod)%mod;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    t=1;
    //cin>>t;
    while(t--){
        solution();
        cout<<"\n";
    }
    return 0;
}
