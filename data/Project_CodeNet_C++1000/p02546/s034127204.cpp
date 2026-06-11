//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define in(x, l, r) (ll)(l) <= (x) && (x) < (ll)(r)

int main() {
    string S;
    cin >> S;
    if (S[S.size()-1] == 's') {
        cout << S + "es" << endl;
    } else {
        cout << S + "s" << endl;
    }
}