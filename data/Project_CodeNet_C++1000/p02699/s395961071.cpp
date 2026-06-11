#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int s, w; cin >> s >> w;
    string  ans = "unsafe";
    if (w < s) ans = "safe";
    cout << ans << endl;
    return 0;
}