#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void kaibun(string &S, string &ans) {
    rep(i,S.size()/2) {
        if (S.at(i) != S.at(S.size() - 1 - i)) {
            ans = "No";
        }
    }
}

int main() {
    string S;
    cin >> S;
    string ans = "Yes";
    int N = S.size();

    string bS = S.substr(0, (N - 1) / 2);
    string eS = S.substr((N + 3) / 2 - 1);
    kaibun(S, ans);
    kaibun(bS, ans);
    kaibun(eS, ans);

    cout << ans << endl;
}
