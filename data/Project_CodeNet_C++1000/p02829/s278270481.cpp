#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v(2);
    cin >> v[0] >> v[1];

    sort(v.begin(), v.end());

    if (v[0] == 2)
        cout << 1 << endl;
    else if (v[1] == 2)
        cout << 3 << endl;
    else
        cout << 2 << endl;

    return 0;
}
