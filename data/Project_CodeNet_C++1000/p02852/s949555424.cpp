#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
 
typedef long long ll;
 
int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;
    vector<int> ans(0);
    while (N > 0) {
        bool f = false;
        for (int i = M; i > 0; i--) {
            if (i > N) continue;
            if (S[N - i] == '0') {
                ans.push_back(i);
                N -= i;
                f = true;
                break;
            }
        }
        if (!f) {
            cout << "-1\n";
            return 0;
        }
    }
    int n = ans.size();
    rep(i, n) {
        cout << ans[n - 1 - i];
        if (i == n - 1) cout << endl;
        else cout << " ";
    }
}