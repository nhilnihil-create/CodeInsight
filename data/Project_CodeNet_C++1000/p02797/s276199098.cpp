#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, K, S;
    cin >> N >> K >> S;

    rep(i, K) cout << S << " ";
    ll num;
    if (S > 10e6)
        num = 1;
    else
        num = 10e8;
    rep(i, N - K) cout << num << " ";
}