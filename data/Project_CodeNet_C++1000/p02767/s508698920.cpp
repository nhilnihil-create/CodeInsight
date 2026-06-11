#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll sum = 0;
    for (auto x : arr) sum += x;
    ll mid1 = sum / n, mid2 = mid1 + 1;
    
    ll ans = 0;
    for (int i = 0; i < n; i++) ans = ans + (arr[i] - mid1) * (arr[i] - mid1);
    ll temp = 0;
    for (int i = 0; i < n; i++) temp = temp + (arr[i] - mid2) * (arr[i] - mid2);

    cout << min(ans, temp) << endl;
}