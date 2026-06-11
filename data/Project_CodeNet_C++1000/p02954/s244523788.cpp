#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans(n);
    rep(i,2) {
        int cnt = 0;
        rep(j,n) {
            if (s[j] == 'R') cnt++;
            else {
                ans[j] += cnt/2;
                ans[j-1] += (cnt+1)/2;
                cnt = 0;
            }
        }
        reverse(ans.begin(), ans.end());
        reverse(s.begin(), s.end());
        rep(j,n) {
            if (s[j] == 'L') s[j] = 'R';
            else s[j] = 'L';
        }
    }
    rep(i,n) printf("%d\n", ans[i]);
    return 0;
}