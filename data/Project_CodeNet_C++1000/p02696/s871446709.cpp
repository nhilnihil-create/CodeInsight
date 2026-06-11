#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll A, B, N;
    cin >> A >> B >> N;
    ll ans;
    if (N >= B) {
        ll x = B * ((N + 1) / B) - 1;
        ans = floor(A * x / B) - A * floor(x / B);
    } else {
        ans = floor(A * N / B) - A * floor(N / B);
    }
    cout << ans << endl;
}