#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

//
// 素因数分解 (単体のNに対して、sqrt(N)まで試し割り)
//
vector<pair<ll, int>> factorize(ll n) {
    vector<pair<ll, int>> res;
    for(ll i = 2; i*i <= n; i++) {
        if (n%i != 0) continue;
        res.emplace_back(i,0);
        while (n%i == 0) {
            n/=i;
            res.back().second++;
        }
    }
    if (n!=1) res.emplace_back(n,1);
    return res;
}

int f(int x) {
    int res = 0;
    while (x >= res+1) {
        x -= (res+1);
        res++;
    }
    return res;
}

int main() 
{
    ll n;
    cin >> n;
    if (n==1) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    for (auto p : factorize(n)) {
        ans += f(p.second);
    }
    cout << ans << endl;
    return 0;
}