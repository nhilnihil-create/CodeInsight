#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    int a, b, c, k; cin >> a >> b >> c >> k;
    int cnt = 0;
    while (b<=a) cnt++, b *= 2;
    while (c<=b) cnt++, c *= 2;
    cout << (cnt<=k? "Yes": "No") << endl;
}
