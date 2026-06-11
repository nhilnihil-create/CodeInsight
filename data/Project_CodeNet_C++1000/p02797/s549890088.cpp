#include <bits/stdc++.h>
using namespace std;
int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n, k, s;
        cin >> n >> k >> s;
        for(int i = 0; i < k; ++i) cout << s << " ";
        for(int i = 0; i < n - k; ++i) cout << (s == 1000000000 ? 1000000000 - 1 : 1000000000) << " ";
        return 0;
}
