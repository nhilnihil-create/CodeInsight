#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

char fi[2010][2010];
int sh[2010][2010],sw[2010][2010];

int main(){
    int h,w;
    cin>>h>>w;
    rep(i,h) rep(j,w) cin>>fi[i][j];

    rep(i,h){
        int cnt=1;
        rep(j,w){
            if(fi[i][j]=='.'){
                sw[i][j]=cnt;
                cnt++;
            }
            else cnt=1;
        }
    }
    rep(j,w){
        int cnt=1;
        rep(i,h){
            if(fi[i][j]=='.'){
                sh[i][j]=cnt;
                cnt++;
            }
            else cnt=1;
        }
    }
    rep(i,h){
        for(int j=w-2;j>=0;j--){
            if(fi[i][j]=='.' && fi[i][j+1]=='.') sw[i][j]=sw[i][j+1];
        }
    }
    rep(j,w){
        for(int i=h-2;i>=0;i--){
            if(fi[i][j]=='.' && fi[i+1][j]=='.') sh[i][j]=sh[i+1][j];
        }
    }

    int ans=0;
    rep(i,h){
        rep(j,w){
            ans=max(ans,sh[i][j]+sw[i][j]-1);
        }
    }

    cout<<ans<<endl;
}