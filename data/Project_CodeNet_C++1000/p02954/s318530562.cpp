#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans(n);
    rep(i,2){
        int cnt = 0;
        rep(j,n){
            if(s[j] == 'R') ++cnt;
            else{
                ans[j] += cnt/2;
                ans[j-1] += (cnt + 1) / 2;
                cnt = 0;
            }
        }
        reverse(ans.begin(), ans.end());
        reverse(s.begin(), s.end());
        rep(j,n){
            if(s[j] == 'L') s[j] = 'R';
            else s[j] = 'L';
        }
    }
    rep(i,n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
