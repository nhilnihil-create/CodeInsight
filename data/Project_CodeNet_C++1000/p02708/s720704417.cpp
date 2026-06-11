#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll N, K;
    cin >> N >> K;
    ll sum = 0;
    for (ll i = K; i <= N + 1; i++) {
        sum += (N - i + 1) * i + 1;
        sum %= 1000000007LL;
    }
    cout << sum << endl;
    return 0;
}
