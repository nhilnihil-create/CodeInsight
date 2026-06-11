#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n, 0);
    for (auto i = 0; i < n; i++) cin >> a[i];
    for (auto i = n - 1; i >= n / 2; i--) if(a[i] == 1) b[i]++;
    for (auto i = n / 2 - 1; i >= 0; i--) {
        int cnt = 0, mul = 2;
        while(true) {
            auto j = (i + 1) * mul++;
            if(j > n) break;
            cnt += b[j - 1];
        }
        if(cnt % 2 != a[i]) b[i]++;
//        cout << i << " " << cnt << " " << a[i] << " " << b[i] << endl;
    }

    cout << count(b.begin(), b.end(), 1) << endl;
    for (auto i = 0; i < n; i++) if(b[i]) cout << i + 1 << " ";
    cout << endl;
    return 0;
}