#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &c : p) cin >> c;
    if (is_sorted(all(p))) {
        cout << "YES";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> a = p;
            swap(a[i], a[j]);
            if (is_sorted(all(a))) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
