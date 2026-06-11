#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;


int main() {
    int n, x;
    cin >> n;
    vector <int> cnt(N, 0);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> x;
        cnt[x]++;
        ans += x;
    }   
    int m, y;
    cin >> m;
    while(m--) {
        cin >> x >> y;
        ans -= 1LL * cnt[x] * x;
        ans += 1LL * cnt[x] * y;
        cnt[y] += cnt[x];
        cnt[x] = 0;
        cout << ans << endl;
    }
    
}