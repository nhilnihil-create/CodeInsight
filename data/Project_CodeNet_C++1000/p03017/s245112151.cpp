#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    s = "?" + s;
    for(int i = a; i < c; i++) {
        if(s[i] == s[i+1] && s[i] == '#') {
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = b; i < d; i++) {
        if(s[i] == s[i+1] && s[i] == '#') {
            cout << "No" << endl;
            return 0;
        }
    }
    if(d > c) {
        cout << "Yes" << endl;
        return 0;
    }
    for(int i = b; i <= d; i++) {
        if(s[i] == s[i-1] && s[i] == s[i+1] && s[i] == '.') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
