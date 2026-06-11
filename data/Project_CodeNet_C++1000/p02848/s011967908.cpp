#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define m0(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define asort(x) sort(all(x));
#define dsort(x, t) sort(x.begin(), x.end(), greater<t>());
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MINS(m, s) m.insert(make_pair(s, 1));
#define MFIN(m, s) m.find(s) != m.end()
#define INF (1 << 29)
const int mod = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            if(n != 0 && s[i] + n > 'Z') {
                s[i] = s[i] - 26 + n;
            } else {
                s[i] += n;
            }
        } else {
        }
    }
    cout << s << endl;
    return 0;
}