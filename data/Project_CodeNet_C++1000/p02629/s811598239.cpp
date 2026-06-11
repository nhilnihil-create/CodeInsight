#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using ll = long long;

int main() {
    ll n; cin >> n;

    string res = "";
    while(n) {
        n--;
        res += (char)('a' + (n % 26));

        n /= 26;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    
}