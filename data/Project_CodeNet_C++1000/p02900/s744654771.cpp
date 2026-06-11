#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

vector<ll> fac_prime(ll n){
    vector<ll> prime;
    ll sq = sqrt(n) + 1;

    for(int i = 2; i <= sq; ++i){
        sq = sqrt(n) + 1;
        if(n%i == 0){
            prime.push_back(i);
            while(n%i == 0)n/=i;
        }
    }

    if(n != 1)prime.push_back(n);

    return prime;
}

int main(){
    ll a, b;
    cin >> a >> b;

    vector<ll> fac = fac_prime(a);

    ll ans = 1;
    rep(i, fac.size()){
        if(b % fac[i] == 0)ans++;
    }

    cout << ans << endl;
}