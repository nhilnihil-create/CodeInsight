#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    if(p == 2 || p == 5){
        int64_t ans = 0;
        for(int i = 0; i < n; i++){
            int x = s[n-1-i] - '0';
            if(x % p == 0) ans += (n - i);
        }
        cout << ans << endl;
        return 0;
    }
    vector<int64_t> d(n+1), r(p);
    r[0] = 1;
    int64_t ten = 1;
    for(int64_t i = 0; i < n; i++){
        int64_t x = s[n-1-i] - '0';
        d[i+1] = (d[i] + ten * x) % p;
        ten = ten * 10 % p;
        r[d[i+1]]++;
    }
    int64_t ans = 0;
    for(int i = 0; i < p; i++){
        int64_t cnt = r[i];
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}