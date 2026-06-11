#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double value=0;
    vector<double> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n;i++) {
        if (i == 0) {
            value = v.at(i);
        }
        else {
            value = (value + v.at(i)) / 2;
        }
    }
    cout << value << endl;
}