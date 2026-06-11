#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int MOD = 1e9+7;

typedef pair<ll, ll> pairs;
typedef vector<pairs> p;

struct edge{
    ll to, cost;
};


ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

// 素数
vector<bool> IsPrime;
void sieve(size_t max){
    if(max+1 > IsPrime.size()){
        IsPrime.resize(max+1,true);
    } 
    IsPrime[0] = false;
    IsPrime[1] = false;

    for(size_t i=2; i*i<=max; ++i){
        if(IsPrime[i]){
            for(size_t j=2; i*j<=max; ++j){
                IsPrime[i*j] = false;
            }
        }
    }
}

// べき乗の余り
ll modpow(ll a, ll n, ll mod){
    ll res = 1;
    while(n){
        if(n & 1){
            (res *= a) %= mod;
        }else{
            (a *= a) %= mod;
        }
        n >>= 1;
    }
    return res;
}

// 回文
bool kai(string S){
    bool flag = true;
    for(ll i=0;i<S.size()/2;++i){
        if(S[i] != S[S.size()-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}
// ---------------------------------------------

int main(){
    ll k;
    cin>>k;

    queue<ll> q;
    for(ll i=1;i<=9;++i){
        q.push(i);
    }
    ll num = 1;
    ll ans = 0;
    while(true){
        ll x = q.front();
        q.pop();
        if(num == k){
            ans = x;
            break;
        }
        if(x % 10 != 0){
            q.push(x * 10 + x % 10 - 1);
        }
        q.push(x * 10 + x % 10);
        if(x % 10 != 9){
            q.push(x * 10 + x % 10 + 1);
        }
        num++;
    }
    cout<<ans<<endl;
    return 0;
}