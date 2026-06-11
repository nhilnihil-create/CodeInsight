#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    float arr[n], ans, x = 2;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    ans = arr[0]/pow(2, n-1);
    for(int i = n-1; i >= 1; i--) {
        ans += arr[i]/x;
        x *= 2;
    }
    cout << ans << endl;
    return 0;
}
