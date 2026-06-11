#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d;
    cin >> s;

    if (s[c-1] == '#' || s[d-1] == '#' || c == d) {
        cout << "No" << endl;
        return 0;
    }

    bool ans = true;
    for (int i = a; i < c-1; i++) {
        if (s[i] == '#' && s[i] == s[i+1]) ans = false;
    }
    for (int i = b; i < d-1; i++) {
        if (s[i] == '#' && s[i] == s[i+1]) ans = false;
    }

    bool ok = true;
    if (c > d) {
        ok = false;
        for (int i = b - 1; i < d; i++) {
            if (s[i-1] == '.' && s[i-1] == s[i] && s[i-1]== s[i+1]) ok = true;
        }
    }

    if (ans && ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}