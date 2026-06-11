#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int heights[n];
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    if (n == 1) {
        cout << "Yes";
        return 0;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (heights[i] - 1 > heights[i + 1]) {
            cout << "No";
            return 0;
        } else if (heights[i] - 1 == heights[i + 1]) {
            heights[i]--;
        }
    }
    //Check if valid
    for (int i = 0; i < n - 1; i++) {
        if (heights[i] > heights[i + 1]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
