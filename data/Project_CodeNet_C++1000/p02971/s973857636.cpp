#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    vector<int> sa(n);
    copy(a.begin(), a.end(), sa.begin());
    sort(sa.begin(), sa.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        if (a.at(i) == sa.at(0)) {
            cout << sa.at(1) << endl;
        }
        else {
            cout << sa.at(0) << endl;
        }
    }
    return 0;
}