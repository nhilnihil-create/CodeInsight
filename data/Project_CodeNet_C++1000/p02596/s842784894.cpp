#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int k;
    cin >> k;
    vector<int> a(k);
    int ans = 1;
    int amari = 7%k;
    while (1) {
        if (amari == 0) {
            cout << ans << endl;
            return 0;
        }
        if (a[amari] == 1) {
            cout << -1 << endl;
            return 0;
        }
        a[amari] = 1;
        amari *= 10;
        amari += 7; 
        amari %= k;
        ans++;
    }


    return 0;
}