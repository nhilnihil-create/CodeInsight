#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

signed main(){
    int S;
    cin >> S;
    int x, y;
    const int m = 1000000000;
    x = (m - (S % m))%m;
    y = (x + S)/m;
    cout << "0 0 1000000000 1 " << x << " " << y << endl;
}
