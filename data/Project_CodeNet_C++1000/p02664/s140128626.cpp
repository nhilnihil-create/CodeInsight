#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string t; cin >> t;
    for (auto &c : t) {
        if (c == '?') c = 'D';
    }
    cout << t << endl;
}