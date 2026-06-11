#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ll N, M; cin >> N >> M;
    vector<ll> a(N); REP(i, N) cin >> a[i];

    REP(i, N) a[i] /= 2;
    
    ll lcm_A = 1;
    REP(i, N) {
        lcm_A = lcm(lcm_A, a[i]);
        if (lcm_A > M) break;
    }

    ll p = M / lcm_A;
    if (p%2 == 0) p /= 2;
    else p = p / 2 + 1;

    ll two = 2;
    while (true) {
        int warikireru = 0, warikirenai = 0;
        REP(i, N) {
            if (a[i] % two == 0) warikireru++;
            else warikirenai++;
        }
        if (warikireru == 0) break;
        else if (warikirenai == 0) two *= 2;
        else {
            p = 0;
            break;
        }
    }

    PRINT(p);

    return 0;
}