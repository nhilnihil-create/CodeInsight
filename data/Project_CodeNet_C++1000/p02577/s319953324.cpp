#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    string n; cin >> n;
    ll x = 0;
    for (auto &num: n) {
        x += (int)num-'0';
        x %= 9;
    }
    cout << (x % 9 == 0 ? "Yes" : "No") << endl;
}
