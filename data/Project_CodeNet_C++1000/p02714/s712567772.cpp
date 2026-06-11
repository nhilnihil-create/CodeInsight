#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int r=0,g=0,b=0;
    rep(i,n) {
        if (s[i] == 'R') {
            r++;
        }
        else if (s[i] == 'G') {
            g++;
        }
        else {
            b++;
        }
    }

    ll count = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            int k = j + (j-i);
            if (k >= n) {
                break;
            }
            if (s[i] != s[j] && s[j] != s[k] && s[i] != s[k]) {
                count++;
            }
        }
    }

    ll ans = (ll)r*g*b - count;

    cout << ans << endl;

    return 0;
}