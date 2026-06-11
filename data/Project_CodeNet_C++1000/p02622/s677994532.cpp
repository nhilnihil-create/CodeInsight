#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int ans=0;
    string s,t;
    cin >> s >> t;
    int n = s.size();
    rep(i,n){
        if(s[i]!=t[i]) ans++;
    }
    cout << ans << endl;
}
