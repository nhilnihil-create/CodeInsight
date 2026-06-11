#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned ll
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const int N = 1e5 + 10;

int main() {
    int n;
    cin >> n;
    vector<bool> same(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        same[i] = x == y;
    }
    for (int i = 0; i + 2 < n; ++i) {
        if (same[i] & same[i + 1] & same[i + 2])
            return cout << "Yes" << endl, 0;
    }
    cout << "No" << endl;
}