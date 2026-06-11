
#include <bits/stdc++.h>

using namespace std;

typedef long int lint;
typedef long long int llint;

#define INF 1073741824
#define LINF 4611686018000000000
#define MOD 1000000007

int main() {
    llint a, b, k;
    cin >> a >> b >> k;
    llint ans = a - k;
    ans = b + ans;
    cout << max(0LL, a - k) << " " << min(b, max(0LL, ans)) << endl;
    return 0;
}
