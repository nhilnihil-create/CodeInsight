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
    int N, K;
    ll S, d;
    cin >> N >> K >> S;
    d = INF;
    if(S == INF){
        d = 1;
    }
    rep(i, K){
        cout << S << " ";
    }
    rep(i, N - K){
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
