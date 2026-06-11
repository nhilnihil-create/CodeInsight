#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << (a * b)/ (__gcd(a, b));

    return 0;
}

