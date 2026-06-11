#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n + 1, 0);
    rep(i, n) {
        if(s[i] == '<') a[i + 1] = max(a[i + 1], a[i] + 1);
    }
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '>') a[i] = max(a[i], a[i + 1] + 1); 
    }
    ll ans = 0;
    rep(i, a.size()) ans += a[i]; 

    cout << ans << endl;

    return 0;
}