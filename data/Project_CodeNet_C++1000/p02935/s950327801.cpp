#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);

    sort(a.begin(), a.end());

    double sum = a.at(0);
    for (int i = 1; i < n; i++) {
        sum = (sum + a.at(i)) / 2;
    }

    cout << sum << endl;

    return 0;
}
