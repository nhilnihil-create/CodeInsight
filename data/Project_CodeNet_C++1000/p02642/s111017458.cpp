#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, a[200005] = {}, b[1000006] = {}, c[1000006] = {}, z = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], c[a[i]]++;
    for (int i = 1; i <= 1000000; i++) if (c[i]) for (int j = i + i; j <= 1000000; j += i) b[j] = 1;
    for (int i = 1; i <= n; i++) if (!b[a[i]] && c[a[i]] == 1) z++;
    cout << z;
}
