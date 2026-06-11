#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
const int mod=1000000007;
int main(){
    int h,w;cin>>h>>w;
    vector<string> s(h);
    vector<vector<int>> rightx(h,vector<int>(w,-1));
    vector<vector<int>> righty(h,vector<int>(w,-1));
    rep(i,h)cin>>s[i];
    int ans=0;
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#')continue;
            int tmpx=1;
            int tmpy=1;
            if(rightx[i][j]==-1){
                for(int x=j+1;x<w;x++){
                    if(s[i][x]=='#') break;
                    tmpx++;
                }
                for(int x=j-1;x>=0;x--){
                    if(s[i][x]=='#') break;
                    tmpx++;
                }
                for(int x=j+1;x<w;x++){
                    if(s[i][x]=='#') break;
                    rightx[i][x]=tmpx;
                }
                for(int x=j-1;x>=0;x--){
                    if(s[i][x]=='#') break;
                    rightx[i][x]=tmpx;
                }
                rightx[i][j]=tmpx;
            }
            if(righty[i][j]==-1){
                for(int y=i+1;y<h;y++){
                    if(s[y][j]=='#') break;
                    tmpy++;
                }
                for(int y=i-1;y>=0;y--){
                    if(s[y][j]=='#') break;
                    tmpy++;
                }
                for(int y=i+1;y<h;y++){
                    if(s[y][j]=='#') break;
                    righty[y][j]=tmpy;
                }
                for(int y=i-1;y>=0;y--){
                    if(s[y][j]=='#') break;
                    righty[y][j]=tmpy;
                }
                righty[i][j]=tmpy;
            }
            ans=max(ans,rightx[i][j]+righty[i][j]-1);
        }
    }
    cout<<ans<<endl;
}