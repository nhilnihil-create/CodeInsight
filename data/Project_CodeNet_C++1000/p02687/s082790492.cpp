#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    s[1] = 'R' - s[1] + 'B';
    cout << s << endl;
    return 0;
}
