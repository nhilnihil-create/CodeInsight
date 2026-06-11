#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;
    string ans;
    int t = n % 10;
    if (t == 3) ans = "bon";
    else if (t == 0 || t == 1 || t == 6 || t == 8) ans = "pon";
    else ans = "hon";
    cout << ans << endl;
    return 0;
}