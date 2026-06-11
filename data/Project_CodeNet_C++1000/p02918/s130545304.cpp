#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

string conv(string s) {
    string t = "";
    for (char c : s) if (t.empty() || c != t.back())
        t.push_back(c);
    return t;
}

int cnt(string t) {
    return sz(t);
    // if (sz(t) == 1) return 1;
    // int ans = sz(t) - 2;
    // ans += (t[0] == 'L');
    // ans += (t.back() == 'R');
    // return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    string t = conv(s);
    int m = sz(t);

    int ans = cnt(t);
    for (int z = 0; z < 2; ++z)
    for (int o = 0; o < 2; ++o) 
    for (int p = 0; p < 2; ++p) {
        char c = (z ? 'L' : 'R');
        int nk = k;
        string nt = t;
        if (o == 1) if (nt.back() != c && nk > 0) {nt.back() = c; --nk;}
        if (p == 1) if (nt[0] != c && nk > 0) {nt[0] = c; --nk;}
        for (int i = 1; i < m - 1; ++i)
            if (nk > 0 && nt[i] != c) {--nk; nt[i] = c;}
        string ct = conv(nt);
        // cout << ct << ' ' << cnt(ct) << endl;
        ans = min(ans, cnt(ct));
    }
    std::cout << n - ans << '\n';
    return 0;
}