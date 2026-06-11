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
    string s;
    cin >> s;
    if(s == "SUN") {
        cout << 7 << endl;
    } else if(s == "MON") {
        cout << 6 << endl;
    } else if(s == "TUE") {
        cout << 5 << endl;
    } else if(s == "WED") {
        cout << 4 << endl;
    } else if(s == "THU") {
        cout << 3 << endl;
    } else if(s == "FRI") {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
    return 0;
}