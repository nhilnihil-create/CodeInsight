#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define endl "\n"
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll a, b;
    cin >> a >> b;
    int s = a + b;
    if(s % 2 == 0) {
        cout << s / 2;
    } else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}
