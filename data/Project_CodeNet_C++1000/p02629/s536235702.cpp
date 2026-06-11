#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    string res = "";
    while (n) {
        n--;
        res += (char)('a' + (n % 26));
        n /= 26;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}