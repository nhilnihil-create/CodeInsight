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

const ll mod = 1000000007;

int main() {
    ll A, B;
    cin >> A >> B;
    if((A+B) % 2 != 0){
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << (A+B) / 2 << endl;
    }
    
    return 0;
}
