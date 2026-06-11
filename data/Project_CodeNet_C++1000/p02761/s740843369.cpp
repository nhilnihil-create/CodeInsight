#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)

int rui(int a, int b) {
    int c = 1;
    rep(i,b) {
        c *= a;
    }
    
    return c;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> s(m);
    vector<char> c(m);
    rep(i,m) {
        cin >> s[i] >> c[i];
    }
    
    string ans;
    rep(i,n) {
        ans.push_back('a');
    }
    
    bool tf = true;
    rep(i,m) {
        if(ans[s[i]-1] == 'a' || ans[s[i]-1] == c[i])
            ans[s[i]-1] = c[i];
        else {
            tf = false;
            break;
        }
    }
    
    if(n == 1) {
        if(ans == "a")
            ans = "0";
    }
    else {
        rep(i,n) {
            if(i == 0) {
                if(ans[i] == 'a')
                    ans[i] = '1';
                else if(ans[i] == '0')
                    tf = false;
            }
            else if (ans[i] == 'a'){
                ans[i] = '0';
            }
        }
    }
    
    if(!tf)
        cout << -1 << endl;
    else
        cout << ans << endl;
    
    return 0;
}
