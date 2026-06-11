#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, a, b; cin >> k >> a >> b;
    cout << (a <= b / k * k ? "OK" : "NG") << endl;
    return 0;
}
