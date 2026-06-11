#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll N;
    cin >> N;
    ll ans = N * (N - 1) / 2LL;
    cout << ans << endl;
}
