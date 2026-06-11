#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int>ans(n);
    rep(ri,2) {
        int cnt = 0;
        rep(i,n) {
            if(s[i] == 'R') cnt++;
            else {
                ans[i] += cnt/2;
                ans[i-1] += (cnt+1)/2;
                cnt = 0;
            }
        }
        reverse(ans.begin(),ans.end());
        reverse(s.begin(),s.end());
        rep(i,n) {
            if(s[i] == 'R') s[i] = 'L';
            else s[i] = 'R';
        }
    }
    rep(i,n) {
        cout << ans[i] << endl;
    }
}