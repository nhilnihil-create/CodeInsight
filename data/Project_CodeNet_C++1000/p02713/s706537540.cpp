#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int gcd(int &a, int &b, int &c) {
    int ans = -1;
    rep1(i, max(a, max(b, c))) {
        if(a % i == 0 && b % i == 0 && c % i == 0) ans = max(ans, i);
    }
    return ans;
}
int main() {
    int k;
    cin >> k;
    int ans = 0;
    for (int i = 1; i <= k - 2; i++) {
        for(int j = i + 1; j <= k - 1; j++) {
            for(int l = j + 1; l <= k; l++) ans += 6 * gcd(i, j, l);
        }
    }
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= k; j++) {
            if(j == i) continue;
            ans += 3 * gcd(i, i, j);
        }
    }
    for(int i = 1; i <= k; i++) {
        ans += i;
    }
    cout << ans << endl;
}