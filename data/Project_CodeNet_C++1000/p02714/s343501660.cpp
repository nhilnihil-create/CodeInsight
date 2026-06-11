#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<int> R;
    vector<int> G;
    
    rep(i,S.size()) {
        if (S.at(i) == 'R') {
            R.push_back(i);
        } else if (S.at(i) == 'G') {
            G.push_back(i);
        }
    }
    long ans = R.size() * G.size() * (N - R.size() - G.size());
    rep(i,R.size()) {
        rep(j,G.size()) {
            int pos_min = 2 * min(R.at(i), G.at(j)) - max(R.at(i), G.at(j));
            int pos_max = 2 * max(R.at(i), G.at(j)) - min(R.at(i), G.at(j));
            int pos_middle = (R.at(i) + G.at(j)) / 2;
            if (pos_min >= 0 && S.at(pos_min) == 'B') --ans;
            if (pos_max < S.size() && S.at(pos_max) == 'B') --ans;
            if ((R.at(i) + G.at(j)) % 2 == 0 && S.at(pos_middle) == 'B') --ans;
        }
    }
    cout << ans << endl;
}
