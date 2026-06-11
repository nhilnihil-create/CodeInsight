#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int arr[N], temp[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<int> res;
    for (int i = n; i > 0; i--) {
        int tot = 0;
        for (int j = 2; j * i <= n; j++) {
            tot += temp[i * j];
        }
        if (tot % 2 != arr[i]) temp[i]++, res.push_back(i);
    }
    cout << res.size() << '\n';
    for (auto x: res) cout << x << ' ';
    return 0;
}