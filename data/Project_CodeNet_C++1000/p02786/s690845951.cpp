#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    ll h;
    cin >> h;
    ll ans = 1;
    ll i = 1;
    while(h > 1) {
        h /= 2;
        ans += pow(2,i);
        i++;
    }
    cout << ans << endl;
}