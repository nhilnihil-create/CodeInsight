#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
using ll = long long int;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll mod = 1000000007;

vector<ll> fx(10000005,2);

int main() {
    ll n;
    cin >> n;
    fx[0] = 0; fx[1] = 1;
    for(int i = 2;i <= n / 2 + 1;i++) {
        for(int j = 2;i * j <= n;j++) {
            fx[i*j]++;
        }
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) ans = ans + i * fx[i];
    cout << ans << endl;
}
