#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define speed() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    speed();
    int A, B, M; cin >> A >> B >> M;
    int a[A], b[B];
    rep(i, 0, A) cin >> a[i];
    rep(i, 0, B) cin >> b[i];
    int amount = *min_element(a, a+A) + *min_element(b, b+B);
    rep(i, 0, M) {
        int x, y, c; cin >> x >> y >> c;
        x--; y--;
        amount = min(amount, (a[x] + b[y]) - c);
    }
    cout << amount << endl;
    return 0;
}