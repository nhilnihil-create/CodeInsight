#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int len = sz(s);
    rep(i,len) {
        s[i] = 'A'+(s[i]-'A'+n)%26;
    }
    cout << s << endl;
    return 0;
}
