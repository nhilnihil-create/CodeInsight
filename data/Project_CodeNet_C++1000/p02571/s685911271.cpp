#include<iostream>
#include<algorithm>
using namespace std;

int getHammingDistance(string S, string T, int i) {
    int ans = 0;
    S = S.substr(i, T.size());
    for  (int i = 0; i < T.size(); i++) {
        if (S[i] != T[i]) {
            ans++;
        }
    }
    return ans;
}

int main() {
    string S, T; cin >> S >> T;
    int ans = 1001;
    for (int i = 0; i <= S.size() - T.size(); i++) {
        ans = min(ans, getHammingDistance(S, T, i));
    }
    cout << ans << endl;
}
