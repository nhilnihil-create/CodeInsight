#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << arr[n/2] - arr[n/2 - 1] << endl;
    return 0;
}
