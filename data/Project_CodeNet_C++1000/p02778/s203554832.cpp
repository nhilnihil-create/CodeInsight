#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
        s[i] = 'x';
    }
    cout << s << endl;
    return 0;
}