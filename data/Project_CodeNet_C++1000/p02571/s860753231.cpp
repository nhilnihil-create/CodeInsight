#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    string S, T;
    cin >> S >> T;
    int ans = T.size();
    for (int i = 0; i+T.size() <= S.size(); i++) {
        int a = 0;
        for (int j = 0; j < T.size(); j++) {
            if (S[i+j] != T[j]) {
                a++;
            }
        }
        ans = min(a, ans);
    }
    cout << ans << endl;
}