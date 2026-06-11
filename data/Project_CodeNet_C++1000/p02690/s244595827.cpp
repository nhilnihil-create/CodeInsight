#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int N = 300006;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll x;
    cin >> x;
    for (ll i = -3000; i <= 3000; i++) {
        for (ll j = -3000; j <= 3000; j++) {
            ll A = i * i * i * i * i;
            ll B = j * j * j * j * j;
            if (A - B == x) {
                cout << i << ' ' << j << '\n';
                return 0;
            }
        }
    }
    return 0; 
}
 