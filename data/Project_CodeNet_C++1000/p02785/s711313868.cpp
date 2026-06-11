#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> m(n);
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        cin >> m.at(i);
    }
    sort(m.begin(), m.end(), greater<>());
    int64_t sum = 0;
    for (int i = k; i < n; i++) {
        sum += m.at(i);
    }
    cout << sum << endl;
}
