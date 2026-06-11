#include <bits/stdc++.h>

typedef long long ll;

#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define AA(i) cout << i << endl;
#define AS(i) cout << i << " ";

const int INF = 1001001001;

const double PI = 3.14159;

using namespace std;

//vector<ll> memo(1000007, INF);

int main() {

    ll n, k;
    cin >> n >> k;

    ll h[n];
    rep(i, n)
        cin >> h[i];

    sort(h, h+n);

    ll ans = 0;
    ll j = n - k;
    if (j < 0) k = 0;
    rep(i, j) {
        ans += h[i];
    }

    AA(ans);
}