#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
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
    int tmp;
    rep(i, N) {
        if (s[i] == X) tmp = i+1;
    }
    int ans = 0;
    for (int i = tmp; i < N; ++i) {
        ans += t[i];
    }
    cout << ans << endl;
    return 0;
}
