#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> c(n, 0); 
    int cnt_r = 0;
    rep(i, n){
        if(s[i]=='W')c[i]=1;
        else cnt_r++;
    }
    
    int ans = 0;
    rep(i, cnt_r){
        ans += c[i];
    }
    
    cout << ans << endl;
    
}