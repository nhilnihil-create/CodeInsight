#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
int main() {
    int k, x; cin >> k >> x;
    for(int i = x - (k - 1); i <= x + (k - 1); i++){
        cout << i << ' ';
    }

    return 0;
}