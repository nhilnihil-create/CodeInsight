#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<vector<int>> l(h,vector<int>(w,-1));
    int n=0;

    rep(j,w){
        rep(i,h){
            if(s[i][j]=='.'){
                n++;
            }else{
                rep(k,n) l[i-k-1][j]+=n;
                n=0;
            }
            if(i==h-1){
                rep(k,n) l[i-k][j]+=n;
                n=0;
            }
        }
    }
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='.'){
                n++;
            }else{
                rep(k,n) l[i][j-k-1]+=n;
                n=0;
            }
            if(j==w-1){
                rep(k,n) l[i][j-k]+=n;
                n=0;
            }
        }
    }

    int ans=0;
    rep(i,h){
        rep(j,w){
            ans=max(ans,l[i][j]);
            // cout << l[i][j];
            // if(j!=w-1) cout << ' ';
            // else cout << endl;
        }
    }
    cout << ans << endl;

    return 0;
}   