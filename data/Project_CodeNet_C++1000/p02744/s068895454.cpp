#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC return 0;
using namespace std;
map<string, bool> M;
string s;
int n;
inline void Back(int k, char maxc, string s) {
    if (k == n)
        M[s];
    else for (char c = 'a'; c <= maxc; ++c) {
        if (c == maxc)
            Back(k + 1, maxc + 1, s + c);
        Back(k + 1, maxc, s + c);
    }
}
int main() {
    DAU
    cin >> n;
    Back(0, 'a', "");
    for (const auto& p : M)
        cout << p.first << '\n';
    PLEC
}
