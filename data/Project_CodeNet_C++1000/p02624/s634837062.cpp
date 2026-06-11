#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename key>
using ordered_set = tree<key, null_type, less<key>, rb_tree_tag, tree_order_statistics_node_update>;
#define F first
#define S second
#define T second.first
//#define C second.second
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define all(v) v.begin(),v.end()
#define OO 0x3f3f3f3fLL
#define INF 0x3f3f3f3f3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll,pair<ll,ll>> piii;
const int N = 1e7+5, M= 20, mod = 1000000000;
const double EPS = 1e-10;


ll A[N];
void sieve(ll n){
    for (ll i = 1; i <= n; ++i)
     for (ll j = i; j <= n; j += i)
      ++A[j];
}

int main(){
    FIO
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ll n;
    cin>>n;
    sieve(n);
    ll ans = 0;
    for(ll i=1; i<=n; i++){
        ans+= A[i]*i;
    }
    cout<<ans;
}
