#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> s(m),c(m),ans(n);
    rep(i,m){
        cin>>s[i]>>c[i];
        if(s[i]!=n&&c[i]==0){
            cout<<-1;
            return 0;
        }
        rep(k,i){
            if(s[i]==s[k]&&c[i]!=c[k]){
                cout<<-1;
                return 0;
            }
        }
        ans[s[i]-1]=c[i];
    }
    if(ans[0]==0&&n!=1) ans[0]=1;//一番左が分からない場合
    rep(i,n) cout<<ans[i];
}