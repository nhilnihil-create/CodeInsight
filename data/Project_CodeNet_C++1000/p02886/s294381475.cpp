#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += data[i] * data[j];
        }
    }
    for (int i = 0; i < n; i++) {
        sum -= data[i] * data[i];
    }
    cout << sum / 2 << endl;
    return 0;
}