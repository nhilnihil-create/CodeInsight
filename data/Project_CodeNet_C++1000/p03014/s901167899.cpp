#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int h,w;
    cin>>h>>w;
    char fi[h][w];
    rep(i,h) rep(j,w) cin>>fi[i][j];

    int cw[h][w];
    rep(i,h) rep(j,w) cw[i][j]=0;
    rep(i,h){
        int c=1;
        rep(j,w){
            if(fi[i][j]=='#') c=1;
            else{
                cw[i][j]=c;
                c++;
            }
        }
    }
    rep(i,h){
        for(int j=w-2;j>=0;j--){
            if(cw[i][j]==0) continue;
            if(cw[i][j+1]==0) continue;
            cw[i][j]=cw[i][j+1];
        }
    }
    int ch[h][w];
    rep(i,h) rep(j,w) ch[i][j]=0;
    rep(j,w){
        int c=1;
        rep(i,h){
            if(fi[i][j]=='#') c=1;
            else{
                ch[i][j]=c;
                c++;
            }
        }
    }
    rep(j,w){
        for(int i=h-2;i>=0;i--){
            if(ch[i][j]==0) continue;
            if(ch[i+1][j]==0) continue;
            ch[i][j]=ch[i+1][j];
        }
    }

    /*
    rep(i,h){
        rep(j,w){
            cout<<ch[i][j]<<" ";
        }
        cout<<endl;
    }*/

    int ans=0;
    rep(i,h){
        rep(j,w){
            ans=max(ans,ch[i][j]+cw[i][j]);         
        }
    }

    cout<<ans-1<<endl;
}
