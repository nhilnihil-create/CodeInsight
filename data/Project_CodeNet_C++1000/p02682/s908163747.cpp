#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if(k <= a) cout << k << endl;
    else if(k <= a+b) cout << a << endl;
    else cout << a - (k-a-b) << endl;
}
