#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    ll x = min(n, b-1);
    cout << ll(a*x/b) - a * ll(x/b) << endl;
    return 0;
}