#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };
const int LIT = 1e9 + 7;
int n, m;
int arr[200001];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            ans += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }
    cout << ans;

}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
