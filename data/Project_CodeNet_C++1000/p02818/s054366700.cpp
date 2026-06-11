#include <bits/stdc++.h>

#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)

#define MOD 1000000007
#define INF 1000000000

using ll = long long int;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    ll A, B, K; cin >> A >> B >> K;

    if(A > K) A -= K;
    else if(A + B > K) {
        B -= K - A;
        A = 0;
    } else {
        A = 0;
        B = 0;
    }

    cout << A << " " << B << endl;
    return 0;
}
