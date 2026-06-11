#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int d, t, s; cin >> d >> t >> s;
    if((d + s - 1) / s <= t) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
