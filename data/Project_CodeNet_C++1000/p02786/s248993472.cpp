#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main() {
    ll h;
    cin >> h;
    if(h == 1) {
        cout << 1 << endl;
        return 0;
    }
    int p = 0;
    ll ans = 0;
    while(h > 0) {
        ans += (1LL << p);
        h /= 2;
        ++p;
    }
    cout << ans << endl;

    return 0;
}
