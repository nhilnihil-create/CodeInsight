#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;
#define ll long long
#define INF (int)(1e9+5)
#define MOD (int)(1e9 + 7) 
#define pi 3.14159265

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int len, n;
    cin >> len >> n;
    vector<int> arr(n);
    for(int &i : arr) cin >> i;
    vector<int> res;
    for(int i = 0; i < n - 1; ++i) {
        res.push_back(arr[i+1] - arr[i]);
    }
    res.push_back(len - arr[n-1] + arr[0]);
    sort(res.begin(), res.end());
    int ans = 0;
    for(int i = 0; i < n - 1; ++i) {
        ans += res[i];
    }
    cout << ans << '\n';
    return 0;
}

