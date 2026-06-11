#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == s[1] && s[2] == s[3] && s[1] != s[2]) cout << "Yes";
    else cout << "No" << '\n';
    return 0;
}
