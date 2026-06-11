#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    string s;
    cin >> n >> p;
    cin >> s;
    long long ans = 0;
    if(p == 2 | p == 5) {
        for(int i = 0; i < n; i++) {
            if((s[i] - '0') % p == 0) {
                ans += (i + 1);
            }
        }
    } else {
        vector<int> cnt(p);
        cnt[0] = 1;
        long long tmp = 1;
        long long sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            sum = ((s[i] - '0') * tmp + sum) % p;
            ans += cnt[sum];
            cnt[sum]++;
            tmp = tmp * 10 % p;
        }
    }
    cout << ans << endl;
    return 0;
}