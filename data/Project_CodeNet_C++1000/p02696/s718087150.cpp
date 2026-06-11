#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)

int main() {
    int64_t a, b, n;
    cin >> a >> b >> n;
    int64_t x = min(b-1,n);
    int64_t ans = (a*x)/b-a*(x/b);
    
    cout << ans << endl;
}
