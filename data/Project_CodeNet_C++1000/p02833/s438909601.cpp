#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    ll n;
    cin >> n;
    if(n % 2) {
        puts("0");
        return 0;
    }
    ll ans = 0;
    ll d = 10;
    while(n / d > 0) {
        ans += n / d;
        d *= 5;
    }
    cout << ans << endl;

    return 0;
}
