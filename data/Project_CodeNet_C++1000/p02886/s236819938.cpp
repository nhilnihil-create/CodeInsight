#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> d(n);
    vector<int> s(n);
    int tot = 0;
    for(int i=0; i<n; i++){
        cin >> d[i];
        tot += d[i];
        s[i] = tot;
    }
    int ans = 0;
    for(int i=1; i<n; i++){
        ans += d[i] * s[i-1];
    }
    cout << ans << endl;
}