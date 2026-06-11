#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'


int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    cout << 360 / gcd(360, n) << endl;
    return 0;
}
