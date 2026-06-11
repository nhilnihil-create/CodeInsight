#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    vector<int> b(n - 1);
    for (int i = 1; i < n; i++) {
        b.at(i - 1) = a.at(i) - a.at(i - 1);
    }
    b.push_back(a.at(0) + k - a.at(n - 1));
    cout << k - *max_element(b.begin(), b.end()) << endl;
    return 0;
}