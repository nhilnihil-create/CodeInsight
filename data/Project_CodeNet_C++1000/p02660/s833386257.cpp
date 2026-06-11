#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<deque>
#include<bitset>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T&a , T b){ if(a<b){ a=b; return true; } else{ return false; } }
template<class T> inline bool chmin(T&a , T b){ if(a>b){ a=b; return true; } else{ return false; } } 

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

vector<P> prime_factorize(ll n){
    vector<P> res;

    for(ll a=2; a*a<=n; ++a){
        if(n%a != 0) continue;
        ll ex = 0; // 指数

        while(n%a==0){
            ++ex;
            n /= a;
        }

        // vectorにpairをpush_back()する時、make_pair()にしないと怒られる
        res.push_back(P(a, ex));
    }

    // 最後にnが残った時
    if(n != 1) res.push_back(P(n,1));
    return res;
}


int main(){
    ll n;
    cin >> n;

    vector<P> v;
    v = prime_factorize(n);

    ll ans = 0;
    for(auto &x : v ){
        int b = 1;
        x.second -= b;
        ans++;
        while( (x.second-(b+1)) >= 0 ){
            b++;
            x.second -= b;
            ans++;
        }
    }

    cout << ans << endl;
}