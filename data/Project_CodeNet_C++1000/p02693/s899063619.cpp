#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)

int main() {
    int k, a, b;
    cin >> k >> a >> b;
    if(a <= b/k*k) cout << "OK" << endl;
    else cout << "NG" << endl;
}
