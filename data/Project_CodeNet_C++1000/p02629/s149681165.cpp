#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    ll n, m = 1, o = 0;
    string s;
    cin >> n;
    n--;
    while (1) {
        m *= 26;
        o++;
        if (n < m) {
            while (o--) s += n % 26 + 'a', n /= 26;
            reverse(s.begin(), s.end());
            cout << s;
            break;
        }
        n -= m;
    }
}
