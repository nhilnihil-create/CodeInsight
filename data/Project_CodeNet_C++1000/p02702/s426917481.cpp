#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int rlist[2019];
int Pow(int a, int n, int mod) {
    if (n == 0) return 1;
    if (n % 2) return (a * Pow(a, n - 1, mod)) % mod;
    else {
        int k = Pow(a, n / 2, mod);
        return (k * k) % mod;
    }
}
int main() {
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < 2019; i++) rlist[i] = 0;
    int now = 0;
    rlist[0]++;
    for (int i = len - 1; i >= 0; i--) {
        int keta = s[i] - 48;
        now = (now + keta * Pow(10, len - 1 - i, 2019)) % 2019;
        rlist[now]++;
    }
    ll ret = 0;
    for (int i = 0; i < 2019; i++) {
        if (rlist[i] >= 2) {
            ret += rlist[i] * (rlist[i] - 1) / 2;
        }
    }
    cout << ret << endl;
    return 0;
}