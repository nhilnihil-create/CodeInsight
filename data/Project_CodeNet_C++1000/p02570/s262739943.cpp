#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long ll;
const long double PI = (acos(-1));
const long long MOD = 1000000007;

static const int  MAX_INT = std::numeric_limits<int>::max();
static const long MAX_LONG = std::numeric_limits<long>::max();
static const ll   MAX_LL = std::numeric_limits<long long>::max();

#define rep(i,n) REP(i,0,n)
#define REP(i,x,n) for(int i=x;i<n;++i)

///////////////////////////////////////////////////
// ------------------- utils ------------------- //
///////////////////////////////////////////////////
// change min/max
template<class T> inline bool chMin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chMax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

///////////////////////////////////////////////////
// ------------------- main -------------------- //
///////////////////////////////////////////////////
void Main() {
    ll D, T, S; cin >> D >> T >> S;
    cout << (T * S >= D ? "Yes" : "No")  << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout << std::fixed << std::setprecision(15);
    Main();

    double tmp;
    cin >> tmp;

    return 0;
}
