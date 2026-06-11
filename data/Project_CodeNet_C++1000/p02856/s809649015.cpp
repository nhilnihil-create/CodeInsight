
#include <iostream>
#include <fstream>
#include <algorithm>       // for next_permutation
#include <vector>

#define DEBUG 0
#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;


int main() {
    ll S = 0;
    ll D = 0;
    ll N;
    cin >> N;
    REP(i,N)
    {
        ll c,d;
        cin >> d >> c;
        D += c;
        S += d * c;
    }
    ll res;
    res = (D-1) + ((S-1) / 9);

    cout << res << endl;

    return 0;
}
