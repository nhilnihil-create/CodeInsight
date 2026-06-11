#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int max_a = 0, next_max_a = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        a.at(i) = x;

        if (x > max_a)
            max_a = x;
        else if (x <= max_a)
            next_max_a = max(next_max_a, x);
    }

    for (auto i : a)
        cout << (i == max_a ? next_max_a : max_a) << endl;
}