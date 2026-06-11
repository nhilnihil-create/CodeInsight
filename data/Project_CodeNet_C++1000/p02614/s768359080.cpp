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
    int h,w,k;
    cin>>h>>w>>k;
    char c[h][w];
    rep(i,h){
        rep(j,w) cin>>c[i][j];
    }
    int ans=0;
    for(int i=0;i<(1<<h);i++){
        for(int j=0;j<(1<<w);j++){
            int cnt=0;
            rep(l,h){
                if(i&(1<<l)) continue;
                rep(m,w){
                    if(j&(1<<m)) continue;
                    if(c[l][m]=='#') cnt++;
                }
            }
            if(cnt==k) ans++;
        }
    }
    cout<<ans;
}