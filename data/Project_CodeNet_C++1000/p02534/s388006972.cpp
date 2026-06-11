#include <bits/stdc++.h>
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> k;
    string s;
    while (k--) {
        s += "ACL";
    }
    cout << s << endl;
}