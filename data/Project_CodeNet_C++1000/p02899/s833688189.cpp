#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    vector<int> ans(n);
    for (int j = 0; j < n; j++) {
        ans.at(a.at(j) - 1) = j + 1;
    }
    for (auto k : ans) {
        cout << k << " ";
    }
    cout << endl;
}
