#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    string res;
    while (n) {
        --n;
        res += (n % 26) + 'a';
        n /= 26;
    }   
    reverse(res.begin(), res.end());
    cout << res << '\n';
    return 0;
}
