#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    string s;
    cin >> s;

    string s1;

    int q;
    cin >> q;
    rep(i,q) {
        int t,f;
        char c;
        cin >> t;

        if (t == 1) {
            swap(s,s1);
        }
        else {
            cin >> f >> c;
            if (f == 1) {
                s1 += c;
            }
            else {
                s += c;
            }

        }
    }

    reverse(s1.begin(), s1.end());
    s1 += s;
    cout << s1 << endl;
    return 0;
}