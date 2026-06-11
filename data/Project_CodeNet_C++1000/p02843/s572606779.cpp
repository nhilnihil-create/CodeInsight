#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x; cin >> x;
    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        if (100*i <= x && x <= 100*i+5*i) {
            ans = 1;
            break;
        }
    }
    cout << ans << endl;
}