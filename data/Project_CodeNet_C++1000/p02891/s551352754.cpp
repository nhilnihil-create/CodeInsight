#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
ll k, a, b, sol;

bool sameAll(string x) {
    for(ll i = 1; i < x.size(); i++) {
        if(x[i] != x[i - 1]) return false;
    }
    return true;
}

ll ganti(string x) {
    ll ans = 0;
    for(ll i = 0; i < x.size() - 1; i++) {
        if(x[i] == x[i + 1]) {
            ans++; i++;
        }
    }
    return ans;
}

bool BF(string x) {
    return x[0] == x[x.size() - 1];
}

ll CFront(string x) {
    ll fr = 0;
    for(ll i = 0; i < x.size(); i++) {
        if(x[i] == x[0]) fr++;
        else break;
    }
    return fr;
}

ll CBack(string x) {
    ll ba = 0;
    for(ll i = x.size() - 1; i >= 0; i--) {
        if(x[i] == x[x.size() - 1]) ba++;
        else break;
    }
    return ba;
}

void solve() {
    cin >> s >> k;
    if(sameAll(s)) cout << s.size() * k / 2 << "\n";
    else if(!BF(s)) cout << ganti(s) * k << "\n";
    else if(BF(s)) {
        a = CFront(s);
        b = CBack(s);
        sol = ganti(s) * k - (a / 2 + b / 2 - (a + b) / 2) * (k - 1);
        cout << sol << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

}