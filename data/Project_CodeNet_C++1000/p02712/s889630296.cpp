#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    rep1(i, n) if(i % 3 != 0 && i % 5 != 0) ans += i;
    cout << ans << endl;
}