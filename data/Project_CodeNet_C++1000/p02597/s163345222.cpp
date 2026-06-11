#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int n,ans=1e9;
    cin >> n;
    string s;
    cin >> s;
    int a[n+1],b[n+1];
    a[0]=0;b[0]=0;
    rep(i,n){
        if(s[i]=='W') a[i+1] = a[i]+1;
        else a[i+1] = a[i];
    }
    //rep(i,n+1) cout << a[i];
    reverse(s.begin(),s.end());
    rep(i,n){
        if(s[i]=='R') b[i+1] = b[i]+1;
        else b[i+1] = b[i];
    }
    //rep(i,n+1) cout << b[i];
    rep(j,n+1){
        ans = min(max(a[j],b[n-j]),ans);
    }
    cout << ans << endl;
}