#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> s(M), c(M);
    rep(i,M) {
        cin >> s.at(i) >> c.at(i);
        --s.at(i);
    }
    string ans;
    bool exist = true;
    vector<int> num(N, -1);
    rep(i,M) {
        if (num.at(s.at(i)) != -1 && num.at(s.at(i)) != c.at(i)) {
            exist = false;
            break;
        } else {
            num.at(s.at(i)) = c.at(i);
        }
    }
    if (exist == true) {
        rep(i,N) {
            if (i != 0 || (i == 0 && N == 1)) {
                if (num.at(i) == -1) {
                    ans.push_back('0');
                } else {
                    ans.push_back('0' + num.at(i));
                }
            } else {
                if (num.at(0) == 0) {
                    exist = false;
                    break;
                } else if (num.at(0) == -1) {
                    ans.push_back('1');
                } else {
                    ans.push_back('0' + num.at(0));
                }
            }
        }
    }
    if (exist == false) ans = "-1";
    cout << ans << endl;
}
