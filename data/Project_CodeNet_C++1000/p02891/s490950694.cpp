#include <iostream>
using namespace std;

int main() {
    string s;
    long long k;
    cin >> s >> k;
    long long a = 0, b = 0, n = s.size();
    char now = s[0];
    for (int i = 0; i < n; i++) {
        if (s[i] == now) a++;
        else break;
    } 
    now = s[n-1];
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == now) b++;
        else break;
    }
    long long ans;
    if (a == n) {
        ans = a * k / 2;
    } else {
        now = s[0];
        int sum = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != now) {
                now = s[i];
                sum += (cnt / 2);
                cnt = 1;
            } else {
                cnt++;
                if (i == n - 1) {
                    sum += (cnt / 2);
                }
            }
        }
        if (s[0] == s[n-1]) ans = sum * k - (a/2 + b/2 - (a+b) / 2) * (k-1);
        else ans = sum * k;
    }
    cout << ans << endl;
}