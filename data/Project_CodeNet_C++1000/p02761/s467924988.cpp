#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main(){

    int n, m;

    cin >> n >> m;

    vector<char> s(m);
    vector<char> c(m);
    string str(n, '0');

    rep(i,m) {
        cin >> s[i] >> c[i];
    }
    rep(i,m) {
        if (str[s[i]-'0'-1] == '0' || str[s[i]-'0'-1] == c[i]) {
            str[s[i]-'0'-1] = c[i];
        }
        else {
            cout << -1 << endl;
            return 0;

        }

        if (n > 1 && s[i] == '1' && c[i] == '0') {
            cout << -1 << endl;
            return 0;
        }

    }

    if (n > 1 && str[0] == '0') {
        str[0] = '1';
    }

    cout << str << endl;

    return 0;
} 
