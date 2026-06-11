#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
// #define debug(a) cout << "["; rep(i,a.size()) cout << a[i] << ", "; cout<<"]"<< endl;

const ll mod = 1000000007;

int main() {
    int k; cin >> k;
    vector<int> amari(k+1);
    amari[1] = 7 % k;
    for(int i = 2; i <= k; i++) amari[i] = (amari[i-1] * 10 + 7) % k;
    for(int i = 1; i <= k; i++) {
        if(amari[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}