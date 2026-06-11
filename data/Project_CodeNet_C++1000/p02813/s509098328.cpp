#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int kaijo(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) ans *= i;
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    vector<int> r(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    rep(i,n) r[i] = i+1;
    int a, b = 0;
    int count = 1;
    do {
        bool p_ok = true;
        bool q_ok = true;
        rep(i,n){
            if (r[i]!=p[i]) p_ok = false;
            if (r[i]!=q[i]) q_ok = false;
        }
        if (p_ok) a = count;
        if (q_ok) b = count;
        count++;
    } while (next_permutation(r.begin(), r.end()));
    cout << abs(a-b) << endl;
    return 0;
}
