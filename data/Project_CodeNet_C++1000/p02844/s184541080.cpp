#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    
    int ans = 0;
    
    rep(i, 1000){
        vector<char> c(3, '0');
        int i_ = i;
        rep(j, 3){
            int x = i_%10;
            i_ -= x;
            i_ /= 10;
            c[2-j] += x;
        }
        
        int cnt = 0;
        rep(j, n){
            if(c[cnt]==s[j])cnt++;
        }
        if(cnt==3)ans++;
    }
    
    cout << ans << endl;
}