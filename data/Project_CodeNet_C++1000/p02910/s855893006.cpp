#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    string s;
    bool ans = true;
    cin >> s;
    rep(i, s.size()) {
        if (i % 2 == 0) {
            if (s[i] == 'L')ans = false;
        }
        else {
            if (s[i] == 'R')ans = false;
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
