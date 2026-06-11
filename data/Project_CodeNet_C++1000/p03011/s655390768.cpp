#include <bits/stdc++.h>
using namespace std;

int main () {
    vector<int> v(3, 0);
    for (int i = 0; i < 3; ++i) cin >> v[i];

    sort(v.begin(), v.end());
    
    int ans = 0;
    for (int i = 0; i < 2; ++i) ans += v[i];

    cout << ans << endl;
}

