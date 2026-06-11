#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template < typename T > using oset = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
// find_by_order(k) (k+1)th largest element
// order_of_key(k) no of elements <=k

typedef long long ll;
typedef long double ld;
#define endl '\n'
#define rep(i,n)  for(ll i = 0; i < (n); ++i)
#define repA(i, a, n)  for(ll i = a; i <= (n); ++i)
#define repD(i, a, n)  for(ll i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define ff first
#define ss second
#define pb push_back
typedef vector<ll> vll;
typedef vector<pair<ll,ll>> vpl;
const ld PI = 4*atan((ld)1);
const ll INF = LLONG_MAX;
const ll mod = 1e9+7;

// const ll N = 5000;
map<ll,ll> mp;
void Pf(ll a){
    ll f=0;
    while(a%2==0){
        a/=2;
        if(!f){
            mp[2]++;
            f=1;
        }
    }
    f=0;
    // cout << a << endl;
    for(ll i=3;i<=sqrt(a);i+=2){
        f=0;
        while(a%i==0){
            if(!f){
                mp[i]++;
                f=1;
            }
            a/=i;
        }
    }
    f=0;
    if(a>2){
         if(!f)mp[a]++;
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll tt=1;
        // cin >> tt;
    repA(qq,1,tt){
        ll n;cin >> n;
        vll a(n);
        ll g;
        rep(i,n){
            cin >> a[i];
            // if()
            Pf(a[i]);
        }
        ll f=0;
        trav(p,mp){
            if(p.ss>=2){
                f=1; break;
            }
        }

        if(f){
            ll ans =1;
            trav(p,mp){
                if(p.ss==n)ans *=p.ff;
            }
            if(ans==1){
                cout << "setwise coprime" << endl;
            }else{
                cout << "not coprime" << endl;
            }
        }else{
            cout << "pairwise coprime" << endl;
        }
    }
}
