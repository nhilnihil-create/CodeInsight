#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    
    int ans = 0;
    rep(i, N) {
        if (i == 0 && S[i] == 'L') continue;
        if (i == N - 1 && S[i] == 'R') continue;
        if (S[i] == 'L') {
            if (S[i - 1] == 'L') ++ans;
        } else {
            if (S[i + 1] == 'R') ++ans;
        }
    }
    cout << min(N - 1, ans + 2 * K) << endl;
    return 0;
}
