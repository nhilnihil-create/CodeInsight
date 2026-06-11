#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    string s;
    cin >> n >> s;
    if(s.size() % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    int x = s.size() / 2;
    rep(i, x) {
        if(s[i] != s[i + x]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
