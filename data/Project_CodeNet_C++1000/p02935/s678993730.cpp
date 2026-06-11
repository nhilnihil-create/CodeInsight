
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 55;
int a[N];
int n;
double res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    res = a[0];
    for (int i = 1; i < n; ++i) {
        res = (res + a[i]) / 2;
    }
    cout << res << endl;

    return 0;
}

