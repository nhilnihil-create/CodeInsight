#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n, k; cin >> n >> k;
    vector<int> num(n, 0);
    for (int i = 0; i < k; i++) {
        int d; cin >> d;
        for (int j = 0; j < d; j++) {
            int a; cin >> a;
            num[--a]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (num[i] == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}