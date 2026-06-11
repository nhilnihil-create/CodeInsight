#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, x, check[105] = {0};
    cin >> x >> n;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        check[tmp] = 1;
    }

    int ans, tmp = 1000;
    for(int i = 0; i <= 101; i++) {
        if(check[i] == 0) {
            if(abs(x - i) < tmp) {
                ans = i;
                tmp = abs(x - i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}