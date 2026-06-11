#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;


int main(){
    ll S;
    cin >> S;
    if(S == 1000000000000000000) {
        cout << 0 << " " << 0 << " " << 1000000000 << " " << 0 << " " << 0 << " " << 1000000000
             << endl;
        return 0;
    }
    ll x0 = 0, y0 = 0, x1 = 1000000000, x2 = 1;
    ll y2 = (S / 1000000000) + 1;
    ll y1 = 1000000000 - (S % 1000000000);

    cout << x0 << " " << y0 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    return 0;
}
