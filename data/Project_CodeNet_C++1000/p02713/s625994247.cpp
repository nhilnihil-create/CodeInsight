#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 2019;

int main() {
    int k;
    cin >> k;
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= k; l++) {
                ans += __gcd(i,__gcd(j,l));
            }
        }
    }
    cout << ans << endl;
    return 0;
}