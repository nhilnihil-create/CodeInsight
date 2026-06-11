#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] + n <= 'Z') {
            s[i] += n;
        } else {
            s[i] = 'A' + n - ('Z' - s[i]) - 1;
        }
    }
    cout << s << endl;
    return 0;
}