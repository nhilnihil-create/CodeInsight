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
    ll h, w;
    cin>>h>>w;
    vector<string> s(h);
    for(ll i=0;i<h;++i){
        cin>>s[i];
    }

    ll l[h][w], r[h][w], u[h][w], d[h][w];
    for(ll i=0;i<h;++i){
        for(ll j=0;j<w;++j){
            if(s[i][j] == '.'){
                if(j == 0){
                    l[i][j] = 1;
                }else{
                    l[i][j] = l[i][j-1] + 1;
                }
            }else if(s[i][j] == '#'){
                l[i][j] = 0;
            }
        }
        for(ll j=w-1;j>=0;--j){
            if(s[i][j] == '.'){
                if(j == w-1){
                    r[i][j] = 1;
                }else{
                    r[i][j] = r[i][j+1] + 1;
                }
            }else if(s[i][j] == '#'){
                r[i][j] = 0;
            }
        }
    }
    for(ll j=0;j<w;++j){
        for(ll i=0;i<h;++i){
            if(s[i][j] == '.'){
                if(i == 0){
                    u[i][j] = 1;
                }else{
                    u[i][j] = u[i-1][j] + 1;
                }
            }else if(s[i][j] == '#'){
                u[i][j] = 0;
            }
        }
        for(ll i=h-1;i>=0;--i){
            if(s[i][j] == '.'){
                if(i == h-1){
                    d[i][j] = 1;
                }else{
                    d[i][j] = d[i+1][j] + 1;
                }
            }else if(s[i][j] == '#'){
                d[i][j] = 0;
            }
        }
    }

    ll ans = 0;
    for(ll i=0;i<h;++i){
        for(ll j=0;j<w;++j){
            ll sum = l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3;
            ans = max(ans, sum);
        }
    }
    cout<<ans<<endl;

    return 0;
}