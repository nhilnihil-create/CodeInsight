#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

int main(){
    int N, R;
    cin >> N >> R;
    if (N >= 10) cout << R << endl;
    else cout << R + 100 * (10 - N) << endl;

    return 0;
}
