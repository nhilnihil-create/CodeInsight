#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool consist(int &bit, int &N, vector<int> &A, vector<vector<int>> &x, vector<vector<int>> &y) {
    rep(j,N) {//j+1人目の証言を検証
        if (bit & (1<<j)) {
            rep(k,A.at(j)) {//k+1番目の証言
                if (bit & (1<<x.at(j).at(k)-1)) {
                    if (y.at(j).at(k) == 0) return false;
                } else {
                    if (y.at(j).at(k) == 1) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int N, X;
    int ans = 0;
    bool Y;
    cin >> N;
    vector<int> A(N);
    vector<vector<int>> x(N), y(N);
    rep(i,N) {
        cin >> A.at(i);
        rep(j,A.at(i)) {
            cin >> X >> Y;
            x.at(i).push_back(X);
            y.at(i).push_back(Y);
        }
    }

    for (int bit = 0; bit < (1<<N); bit++) {
        int ok = 0;
        for (int i = 0; i < N; i++) {
            if (bit & (1<<i)) ++ok;
        }
        if (consist(bit,N,A,x,y)) ans = max(ans, ok);
    }
    cout << ans << endl;
}
