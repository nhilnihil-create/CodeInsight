#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){ 
    Int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;

    vector<Int> vl, vr;

    rep(i,N) {
        if (S[i] == 'o') {
            vl.push_back(i);
            break;
        }
    }
    for(Int j = vl[0] + C + 1; j < N; j++) {
        if (S[j] == 'o' && vl[vl.size()-1] + C < j) {
            vl.push_back(j);
        }
    }

    rep(i,N) {
        if (S[N-1-i] == 'o') {
            vr.push_back(N-1-i);
            break;
        }
    }
    for(Int j = vr[0] - C - 1; j >= 0; j--) {
        if (S[j] == 'o' && vr[vr.size()-1] - C > j) {
            vr.push_back(j);
        }
    }

    if (vl.size() == K && vr.size() == K) {
        reverse(vr.begin(), vr.end());
        rep(i,K) {
            if (vl[i] == vr[i]) cout << vl[i] + 1 << endl;
        }
    }
}
