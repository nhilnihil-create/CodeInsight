#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (k <= data[i]) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}