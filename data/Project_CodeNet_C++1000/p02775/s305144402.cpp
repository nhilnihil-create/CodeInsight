#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string N;
    cin >> N;

    int n = N.size();
    int prev_carry = 0;
    ll sum = 0;

    rrep(i, 0, n) {
        int ni = int(N[i] - '0');

        bool carry;
        if (i != 0 && prev_carry + ni == 5 && int(N[i - 1] - '0') >= 5) {
            carry = true;
        } else if (prev_carry + ni <= 5) {
            carry = false;
        } else {
            carry = true;
        }

        if (carry) {
            sum += 10 - (prev_carry + ni);
            prev_carry = 1;
        } else {
            sum += prev_carry + ni;
            prev_carry = 0;
        }
    }

    cout << sum + prev_carry << endl;
    return 0;
}