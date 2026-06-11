#include <bits/stdc++.h>

#define rr(i, b)    for (int i = 0; i < int(b); i++)
#define vi(n, a) vector <long long> a(n); rr(i, n) cin >> a[i]
#define pvec(a) rr(i, a.size()) cout << a[i] << " "; cout << endl
#define bug(x) cout << #x << " " << x << endl
#define ll long long
#define vii vector <int>
#define PI acos(-1)

int mod = 1e9 + 7;

using namespace std;
int k;

bool check(string s) {

    int l = 0;
    int r = s.size()/2;

    while(r != s.size()) {
        if(s[l] != s[r]) {
            return false;
        }
        l++;
        r++;
    }

    return true;
}

vector<long long> fac(20 + 1);

void fact() {
    fac[0] = 1;
    for(int i = 1; i <= 20; i++) {
        fac[i] = fac[i - 1] * i;
    }
}

void solve() {
    int s;
    cin >> s;

    vii ans(s + 1, 0);

    ans[0] = 1;

    for(int i = 3; i <= s; i++) {
        ans[i] = (ans[i - 1] + ans[i - 3]) % mod;
    }

    cout << ans[s] << endl;
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    //fact();
    int t = 1;
    //cin >> t;

    for(k = 1; k <= t; k++) {
        solve();
    }
    return 0;
}