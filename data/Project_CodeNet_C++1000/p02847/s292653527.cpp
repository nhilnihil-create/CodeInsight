#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii; 
const int N = 2e5+10, mod = 1e9+7;

void solve() {
    string s; cin >> s;
    int a = 0;
    if (s == "SUN") {
        a = 7;
    } else if (s == "MON") {
        a = 6;
    } else if (s == "TUE") {
        a = 5;
    } else if (s == "WED") {
        a = 4;
    } else if (s == "THU") {
        a = 3;
    } else if (s == "FRI") {
        a = 2;
    } else {
        a = 1;
    }
    cout << a << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    return 0;
}