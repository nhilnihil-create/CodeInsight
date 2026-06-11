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
    int n, a[102] = {}, z = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) for (int k = 0; k < j; k++) if (a[i] != a[j] && a[j] != a[k] && a[k] != a[i] && a[i] + a[j] > a[k] && a[j] + a[k] > a[i] && a[k] + a[i] > a[j]) z++;
    cout << z;
}
