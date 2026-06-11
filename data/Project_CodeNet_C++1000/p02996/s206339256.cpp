#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n); // deadline, time taken

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = {b, a};
    }
    sort(arr.begin(), arr.end());
    int curr_time = 0;
    for (int i = 0; i < n; i++) {
        if (curr_time + arr[i].second > arr[i].first) {
            cout << "No" << endl;
            return 0;
        }
        curr_time += arr[i].second;
    }
    cout << "Yes" << endl;
    return 0;
}