#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
ll gcd(ll a, ll b){
    if (a%b == 0) return(b);
    else return(gcd(b, a%b));
}
 
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0; // 指数
        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        // その結果を push
        res.push_back({a, ex});
    }
    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}
/* vector<pair<ll,ll>>で受け取る！
例えば360=2^3*3^2*5は
{{2,3},{3,2},{5,1}}*/

int main() {
    
    ll a,b;cin >> a >> b;
    ll x=gcd(a,b);
    vector<pair<ll,ll>> y=prime_factorize(x);
    cout << y.size()+1 << endl;

    return 0;
}