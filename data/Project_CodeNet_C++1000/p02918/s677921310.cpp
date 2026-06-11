#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int score = 0;
    rep(i, 0, N-1) {
        if (S[i] == S[i+1]) score++;
    }
    int ans = min(score+2*K, N-1);
    cout << ans << endl;
    return 0;
}
