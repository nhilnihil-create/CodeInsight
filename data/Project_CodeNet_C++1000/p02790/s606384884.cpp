#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string a, b;
    cin >> a >> b;
    string s1 = "", s2 = "";
    rep(i, stoi(b)) { s1 += a; }
    rep(i, stoi(a)) { s2 += b; }
    cout << min(s1, s2) << endl;
    return 0;
}
