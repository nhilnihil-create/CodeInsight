#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans(n,0);
    rep(x,2) {
        int counter = 0;
        rep(i,n) {
            if(s[i] == 'R') {
                counter++;
            } else {
                ans[i] += counter / 2;
                ans[i-1] += (counter+1) / 2;
                counter = 0;
            }
        }
        reverse(ans.begin(),ans.end());
        reverse(s.begin(),s.end());
        rep(i,n) {
            if(s[i] == 'R') {
                s[i] = 'L';
            } else {
                s[i] = 'R';
            }
        }
    }
    rep(i,n) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}