#include <bits/stdc++.h>
using namespace std;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)

int main(){
    int N, M;
    cin >> N >> M;
    int s, c;
    string moji;
    vector<pair<int,int>> data(M);
    rep(i, 0, M){
        cin >> s >> c;
        data[i].first = s-1;
        data[i].second = c;
    }
    rep(i, 0, 1000){
        moji = to_string(i);
        bool b = true;
        if (moji.size() != N){
            continue;
        }
        rep(j, 0, M){
            if ((moji[data[j].first] - '0') != data[j].second){
                b = false;
            }
        }
        if (b){
            cout << moji << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}