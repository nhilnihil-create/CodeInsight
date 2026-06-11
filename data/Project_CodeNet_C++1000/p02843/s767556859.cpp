# include <bits/stdc++.h>
# define rep(i, n) for (ll i = 0; i < (n); i++)
# define reps(i, n) for (ll i = 1; i <= (n); i++)
# define foreps(i, m, n) for (ll i = (m); i < (n); i++)
# define len(x) ((int)(x).size())
# define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

int main() {
    ll X; cin >> X;
    ll Q = X / 100;
    ll R = X % 100;
    cout << (R <= Q * 5) << endl;
}