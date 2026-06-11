#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d.at(i);
    }

    int div = n / 2;
    int cnt = 0, abc;
    sort(d.begin(), d.end());
    for (int i = d.at(div-1); i < d.at(div); i++) cnt++;

    cout << cnt << endl;

    return 0;
}
