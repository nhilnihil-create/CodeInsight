#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const double eps = 1e-9;
const ll N = 1e6 + 10;
const int M = 1e9 + 7;
const ll MAX = 1e18 + eps;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};


int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    int mn = (n % 2 == 0 ? a[n / 2 - 1] + a[n / 2] : a[n / 2]);
    int mx = (n % 2 == 0 ? b[n / 2 - 1] + b[n / 2] : b[n / 2]);

    cout << (mx - mn + 1) << endl;
}