#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n%2 != 0) {
        cout << "No" << endl;
        return 0;
    }
    string x = s.substr(0, n/2);
    if (x+x == s) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}