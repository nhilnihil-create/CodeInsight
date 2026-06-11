#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<pair<int, int>> a_i(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a_i.at(i) = make_pair(i + 1, a);
    }

    sort(a_i.begin(), a_i.end(), [](const auto &x, const auto &y) {
        return x.second < y.second;
    });

    for (int i = 0; i < n - 1; i++)
        cout << a_i.at(i).first << ' ';

    cout << a_i.at(n - 1).first << endl;
}