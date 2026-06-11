#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    string s;
    cin >> s;
    
    vector<int> ans(s.size());
    int n = (int)s.size();
    char c = 'R';
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] != c) {
            if(s[i] == 'L') {
                ans[i-1] += (cnt+1) / 2;
                ans[i] += cnt / 2;
                
                c = 'L';
                cnt = 1;
            }
            else {
                ans[i-cnt] += (cnt+1) / 2;
                ans[i-cnt-1] += cnt / 2;
                
                c = 'R';
                cnt = 1;
            }
        }
        else
            cnt++;
    }
    ans[n-cnt] += (cnt+1) / 2;
    ans[n-1-cnt] += cnt / 2;
    
    
    rep(i,n-1) {
        cout << ans[i] << " ";
    }
    cout << ans[n-1] << endl;
    
    
    
    return 0;
}
