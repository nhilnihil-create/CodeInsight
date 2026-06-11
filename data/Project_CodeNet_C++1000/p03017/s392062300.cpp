#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    a--, b--, c--, d--;
    bool ok = true;
    string route_a = s.substr(a, c-a+1);
    string route_b = s.substr(b, d-b+1);
    if (route_a.find("##") != string::npos) ok = false;
    if (route_b.find("##") != string::npos) ok = false;    
    if (d < c && (s.substr(b-1, d-b+3).find("...") == string::npos)) ok = false;

    string ans = "No";
    if (ok) ans = "Yes";
    cout << ans << endl;
}