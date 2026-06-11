#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n, k; cin >> n >> k;
    if(k == 1) cout << 0 << endl;
    else if(0 < n - k) cout << n - k << endl;
    else cout << 0 << endl;


    return 0;
}
