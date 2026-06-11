#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    rep(i, s.size()) {
        if ((i%2==0 && !(s[i] == 'R' || s[i] == 'U' || s[i] == 'D'))
            || (i%2==1 && !(s[i] == 'L' || s[i] == 'U' || s[i] == 'D'))) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}