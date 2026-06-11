#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n; cin >> n;
    V<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll x = 0;
    for(int i = 0; i < n; i++){
        if(i % 2) x -= a[i];
        else x += a[i];
    }

    V<ll> ans(n);
    ans[0] = x / 2;
    for(int i = 0; i < n - 1; i++){
        ans[i + 1] = a[i] - ans[i];
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] * 2 << endl;
    }


    return 0;
}
