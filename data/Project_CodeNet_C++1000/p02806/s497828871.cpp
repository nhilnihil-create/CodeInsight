#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<string> s(N);
    vector<int> t(N);
    rep(i, N) cin >> s[i] >> t[i];
    string X;
    cin >> X;
    int ans = -1;
    rep(i, N) {
        if (s[i] == X) {
            ans = 0;
            continue;
        }
        if (ans < 0) continue;
        ans += t[i];
    }
    cout << ans << endl;
}