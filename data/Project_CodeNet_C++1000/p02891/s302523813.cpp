#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string S;
    long long K;
    cin >> S >> K;
    
    vector<int> renzoku;
    int cnt = 1;
    REP(i, S.size()) {
        if (S[i - 1] != S[i]) {
            renzoku.push_back(cnt);
            cnt = 1;
        } else {
            ++cnt;
        }
    }
    renzoku.push_back(cnt);
    
    if (renzoku.size() == 1) {
        cout << renzoku[0] * K / 2 << endl;
        return 0;
    }
    long long ans = 0;
    if (S[0] == S[S.size() - 1]) {
        ans += renzoku[0] / 2;
        ans += renzoku[renzoku.size() - 1] / 2;
        ans += (renzoku[0] + renzoku[renzoku.size() - 1]) / 2 * (K - 1);
        REP(i, renzoku.size() - 1) ans += renzoku[i] / 2 * K;
    } else {
        for (int x : renzoku) ans += x / 2 * K;
    }
    cout << ans << endl;
    return 0;
}
