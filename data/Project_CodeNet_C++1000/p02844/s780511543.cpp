#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int mod = 1e9+7;

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
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll ans = 0;
    for(ll i=0;i<1000;++i){
        ll c[3];
        c[0] = i / 100;
        c[1] = (i / 10) % 10;
        c[2] = i % 10;
        ll index = 0;
        for(ll j=0;j<n;++j){
            if(s[j] == (c[index] + '0')){
                index++;
            }
            if(index == 3){
                break;
            }
        }
        if(index == 3){
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}