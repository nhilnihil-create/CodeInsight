#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int a, b; cin >> a >> b;
    vector<int> d(3, 0);
    d[--a]++;
    d[--b]++;
    for (int i = 0; i < d.size(); i++) {
        if (d[i] == 0) cout << i + 1 << endl;
    }
    return 0;
}