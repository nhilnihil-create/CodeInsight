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
    string s;
    cin>>s;
    ll Q;
    cin>>Q;
    bool flag = true;
    vector<char> x;
    vector<char> y;
    for(ll i=0;i<Q;++i){
        ll a;
        cin>>a;

        if(a == 1){
            if(flag){
                flag = false;
            }else{
                flag = true;
            }
        }else if(a == 2){
            ll f;
            char c;
            cin>>f>>c;
            if(f == 1){
                if(flag){
                    x.push_back(c);
                }else{
                    y.push_back(c);
                }
            }else if(f == 2){
                if(flag){
                    y.push_back(c);
                }else{
                    x.push_back(c);
                }
            }
        }
    }

    if(flag){
        for(ll i=x.size()-1;i>=0;--i){
            cout<<x[i];
        }
        cout<<s;
        for(ll i=0;i<y.size();++i){
            cout<<y[i];
        }
        cout<<endl;
    }else{
        for(ll i=y.size()-1;i>=0;--i){
            cout<<y[i];
        }
        reverse(s.begin(), s.end());
        cout<<s;
        for(ll i=0;i<x.size();++i){
            cout<<x[i];
        }
        cout<<endl;
    }

    return 0;
}