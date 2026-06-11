#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

char fi[2020][2020];
int cw[2020][2020],ch[2020][2020];

int main(){
    int h,w;
    cin>>h>>w;
    rep(i,h){
        rep(j,w){
            cin>>fi[i][j];
        }
    }

    rep(i,h){
        int cnt=1;
        rep(j,w){
            if(fi[i][j]=='.'){
                cw[i][j]=cnt;
                cnt++;
            }
            else{
                cnt=1;
            }
        }
        for(int j=w-2;j>=0;j--){
            if(fi[i][j]=='.' && fi[i][j+1]=='.'){
                cw[i][j]=cw[i][j+1];
            }
        }
    }

    rep(j,w){
        int cnt=1;
        rep(i,h){
            if(fi[i][j]=='.'){
                ch[i][j]=cnt;
                cnt++;
            }
            else{
                cnt=1;
            }
        }
        for(int i=h-2;i>=0;i--){
            if(fi[i][j]=='.' && fi[i+1][j]=='.'){
                ch[i][j]=ch[i+1][j];
            }
        }
    }

    int ans=0;
    rep(i,h){
        rep(j,w){
            if(fi[i][j]=='.') ans=max(ans,ch[i][j]+cw[i][j]-1);
        }
    }

    cout<<ans<<endl;
}