#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k; cin >> n >> k;
    int tmp = n - k;
    cout << ((k == 1) ? 0 : tmp) << endl;
    return 0;
}