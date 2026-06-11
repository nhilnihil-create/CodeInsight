#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int n, v[55];
long long s;
int main() {
    DAU
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        for (int j = 1; j < i; ++j)
            s += v[i] * v[j];
    }
    cout << s;
    PLEC
}
