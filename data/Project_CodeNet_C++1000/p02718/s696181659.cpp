#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define endl "\n"
typedef long long ll;

const int BIG_NUM = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    int count = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] * 4 * m >= sum) {
            count++;
        } else {
            break;
        }
    }
    if(count >= m) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
