#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n], l[n]{INT_MIN}, r[n]{INT_MIN};
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++) {
        l[i] = max(l[i-1], arr[i-1]);
    }
    for(int i = n-2; i >= 0; i--) {
        r[i] = max(r[i+1], arr[i+1]);
    }
    for(int i = 0; i < n; i++) {
        cout << max(l[i], r[i]) << endl;
    }
    return 0;
}
