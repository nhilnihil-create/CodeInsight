#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    long n,ans=0;
    string s;
    cin >> n >> s;
    int r[4001]={},g[4001]={},b[4001]={};
    rep(i,n){
        if(s[i]=='R') r[i+1] = r[i] + 1;
        else r[i+1] = r[i];
        if(s[i]=='G') g[i+1] = g[i] + 1;
        else g[i+1] = g[i];
        if(s[i]=='B') b[i+1] = b[i] + 1;
        else b[i+1] = b[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int a = 'R'+'B'+'G';
            if(s[i]==s[j]) continue;
            char d = a-s[i]-s[j];
            int cur = 0;
            if(d=='R') cur = r[n]-r[j];
            if(d=='G') cur = g[n]-g[j];
            if(d=='B') cur = b[n]-b[j];
            if(s[2*j-i]==d) cur--;
            ans += cur;
        }
    }
    cout << ans << endl;
}