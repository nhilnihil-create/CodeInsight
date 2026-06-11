#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;
    vector<int> ans;
    int x = N;
    while (x > 0) {
        bool f = true;
        for (int i = min(M, x); i > 0; i--) {
            if (S[x - i] == '0') {
                ans.push_back(i);
                x -= i;
                f = false;
                break;
            }
        }
        if (f) {
            cout << "-1\n";
            return 0;
        }
    }
    rep(i, ans.size()) {
        cout << ans[ans.size() - 1 - i];
        if (i == ans.size() - 1) cout << "\n";
        else cout << " ";
    }
}