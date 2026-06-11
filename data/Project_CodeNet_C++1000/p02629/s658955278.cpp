#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    long long n;
    cin >> n;
    string ans = "";
    while (n > 0) {
        n--;
        ans += char('a' + n % 26);
        n /= 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}