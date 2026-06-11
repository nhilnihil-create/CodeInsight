#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    int n,k; cin >> n >> k;
    string s; cin >> s;
    int cnt = 0;
    rep(i,n-1) {
        if (s[i] == s[i+1]) cnt++;
    }
    cout << min(2*k+cnt,n-1) << endl;
    return 0;
}
