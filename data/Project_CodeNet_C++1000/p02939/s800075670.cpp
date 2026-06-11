#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string S;
    cin >> S;
    
    vector<char> K;
    rep(i, S.size()) {
        if (i == 0) {
            K.push_back(S[i]);
            continue;
        }
        if (S[i] == K.back()) {
            if (i != S.size() - 1) {
                K.push_back('{');
                ++i;
            }
        } else {
            K.push_back(S[i]);
        }
    }
    cout << K.size() << endl;
    return 0;
}
