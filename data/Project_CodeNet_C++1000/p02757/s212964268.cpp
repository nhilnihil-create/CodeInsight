#include <bits/stdc++.h>
using namespace std;

long long s[200005];
long long cnt[10005];

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, p;
    cin >> n >> p;
    string str;
    cin >> str;

    long long res = 0;
    if (p != 2 && p != 5) {
        int base = 1;
        for (int i = n - 1; i >= 0; i--) {
            s[i] = s[i + 1] + base * (str[i] - '0');
            s[i] %= p;
            cnt[s[i]]++;

            base *= 10;
            base %= p;
        }

        cnt[s[n]]++;
        for (int i = 0; i < p; i++) {
            res += cnt[i] * (cnt[i] - 1) / 2;
        }
        cout << res;
    }
    else {
        for (int i = n - 1; i >= 0; i--) {
            if ((str[i] - '0') % p == 0) {
                res += i + 1;
            }
        }
        cout << res;
    }
    return 0;
}