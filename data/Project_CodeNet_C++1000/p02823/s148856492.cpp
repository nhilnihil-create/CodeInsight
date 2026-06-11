#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    ll ans;
    if (A == B)
        ans = 0;
    else if ((B - A) % 2 == 0)
        ans = (B - A) / 2;
    else {
        ll can1 = A + (B - A - 1) / 2;
        ll can2 = N - B + (B - A - 1) / 2 + 1;
        ans = min(can1, can2);
    }

    cout << ans << endl;
}