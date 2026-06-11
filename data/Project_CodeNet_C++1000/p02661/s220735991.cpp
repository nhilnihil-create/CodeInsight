#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
    ll n, *a, *b;
    cin >> n;
    a = new ll[n], b = new ll[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    sort(a, a+n);
    sort(b, b+n);

    if (n % 2) {
        cout << b[(n-1)/2] - a[(n-1)/2] + 1 << endl;
        return 0;
    }
    else {
        ll m_a = (a[n/2]+a[n/2-1]), m_b = (b[n/2]+b[n/2-1]);
        cout << m_b - m_a + 1 << endl;
        return 0;
    }
}