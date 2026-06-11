#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int) (n); i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int cnt = 0;
    while(a >= b) {
        b *= 2;
        cnt++;
    }
    while(b >= c) {
        c *= 2;
        cnt++;
    }
    if(cnt <= k) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    return 0;
}
