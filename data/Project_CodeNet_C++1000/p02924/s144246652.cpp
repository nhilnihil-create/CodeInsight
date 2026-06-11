#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    Int ans = (Int)n * (n-1);
    
    cout << ans/2 << endl;
}