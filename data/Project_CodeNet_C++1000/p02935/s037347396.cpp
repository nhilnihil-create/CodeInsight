#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    double value = v[0];
    for (int i = 1; i < n; i++) {
        value = (value + v[i]) / 2;
    }
    cout << setprecision(20) << value << endl;
    return 0;
}