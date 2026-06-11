#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    bool okfalg = true; 

    rep(i, n) {
        if (s[i] != s[n-1-i]) {
            cout << "No" << endl;
            return 0;
        } 
    }
    rep(i, (n-1)/2) {
        if (s[i] != s[n-1-i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = (n + 3) / 2 - 1; i < n; i++) {
        if (s[i] != s[(3 * n - 1) / 2 - i]) {
            cout << "No" << endl;
            return 0;
        }
    }

 
    cout << "Yes" << endl;

    return 0;
}