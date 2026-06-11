#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i=0; i< (int)(n); i++)
typedef long long ll;
bool DEBUG = true;

// find maximum kouyakusuu
// souinsuu bunkai the maximum kouyakusuu
// return the num of kinds of soinsuu + 1

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

// bool isseen(vector<int>& primes, int num) {
//     bool seen  = false;
//     rep(pi, primes.size()){
//         if (num % primes[pi] == 0) {
//             seen = true;
//             break;
//         }
//     }
//     return seen;
// }

int main() {
    ll A, B;
    cin >> A >> B;

    ll greatest_common_divisor;
    if (A > B) greatest_common_divisor = gcd(A, B);
    else greatest_common_divisor = gcd(B, A);

    ll ans = 1;
    ll top = greatest_common_divisor;
    for (ll i = 2; i*i < top; i++){
        if (top % i != 0) continue;
        ans++;
        while (top % i == 0) top /= i;
    }
    if (top != 1) ans++;
    cout << ans << endl;
}