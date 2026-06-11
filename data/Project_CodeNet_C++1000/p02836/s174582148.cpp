#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001000;

int main() {
    string s; cin >> s;
    int n = sz(s);
    int cnt = 0;
    rep(i,n/2) {
        if (s[i] != s[n-1-i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
