#include <bits/stdc++.h>
using namespace std;

#define SIZE 5010

long long int d[SIZE], pfx[SIZE];
int pfx1[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int len, qNum;
    cin >> len >> qNum;
    for (int i = 0; i < len; i++)
        cin >> d[i];

    while (qNum--) {
        long long int num, fst, mod;
        cin >> num >> fst >> mod;
        fst %= mod;
        
        pfx[0] = d[0] % mod;
        pfx1[0] = (d[0] % mod == 0); 
        for (int i = 1; i < len; i++) {
            pfx[i] = pfx[i - 1] + (d[i] % mod);
            pfx1[i] = pfx1[i - 1] + (d[i] % mod == 0);
        }
        
        long long int cyc = max(0ll, (num - 1) / len);
        long long int ans = cyc * pfx1[len - 1] + ((num - 1) % len == 0 ? 0 : pfx1[(num - 2 + len) % len]);
        long long int last = fst + cyc * pfx[len - 1] + ((num - 1) % len == 0 ? 0 : pfx[(num - 2 + len) % len]);
        ans += last / mod - fst / mod;
        cout << num - ans - 1 << '\n';
    }
    
    return 0;
}