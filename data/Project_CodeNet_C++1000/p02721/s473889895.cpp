#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    
    vector<int> L(K), R(K);
    int now = 0;
    rep(i, K) {
        while (S[now] == 'x') ++now;
        L[i] = now;
        now += C + 1;
    }
    now = N - 1;
    for (int i = K - 1; i >= 0; --i) {
        while (S[now] == 'x') --now;
        R[i] = now;
        now -= C + 1;
    }
    rep(i, K) {
        if (L[i] == R[i]) cout << L[i] + 1 << endl;
    }
    return 0;
}
