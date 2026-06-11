#include <bits/stdc++.h> //abc148b
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[i + n / 2]) {
            ans++;
        }
    }
    if (n % 2 == 1) {
        cout << "No" << endl;
    } else if (n % 2 == 0 && ans == n / 2) {
        cout << "Yes" << endl;
    } else if (n % 2 == 0 && ans != n / 2) {
        cout << "No" << endl;
    }
    return 0;
}