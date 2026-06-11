#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> a(n);
    double total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        a.at(i) = 1 / a.at(i);
        total += a.at(i);
    }

    cout << 1 / total << endl;

}