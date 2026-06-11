#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll MAX = 1000000007;

ll calc(int a, ll b, ll p){
    if (b == 0){
        return 1;
    } else if (b%2 == 0){
        ll d = calc(a, b/2, p);
        return (d*d) % p;
    } else {
        return (a * calc(a, b-1, p)) % p;
    }
}

int main() {
    int X, Y; cin >> X >> Y;
    int P = X+Y;
    if (P%3 != 0 || X*2 < Y || Y*2 < X){
        cout << 0 << endl;
        return 0;
    }

    int c = P/3;
    int x = X - c;
    int y = Y - c;
    int p = x+y;
    ll ans = 1;

    for (int i = 1; i <= p; i++){
        ans *= i;
        ans %= MAX;
    }
    if (x != 0){
        for (int i = 1; i <= x; i++){
            ans *= calc(i, MAX-2, MAX);
            ans %= MAX;
        }
    }
    if (y != 0){
        for (int i = 1; i <= y; i++){
            ans *= calc(i, MAX-2, MAX);
            ans %= MAX;
        }
    }
    
    cout << ans << endl;
    return 0;

}