#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int n, v[22], res;
int main() {
    DAU
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 2; i < n; ++i)
        if (((v[i] <= v[i-1]) && (v[i] >= v[i+1])) || (v[i] >= v[i-1] && v[i] <= v[i+1]))
            ++res;
    cout << res;
    PLEC
}
