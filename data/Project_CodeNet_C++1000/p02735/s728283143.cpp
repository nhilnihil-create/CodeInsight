#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int h,w;cin>>h>>w;
    char t[h][w];
    int r[h][w];
    rep(i,h)rep(j,w) r[i][j]=100000;
    rep(i,h)rep(j,w) cin>>t[i][j];
    r[0][0]=(t[0][0]=='#')? 1:0;
    queue<pair<int,int>> que;
    que.push({0,0});
    int roty[2]={0,1},rotx[2]={1,0};
    while(que.size()){
        auto p=que.front();que.pop();
        int y=p.first,x=p.second;
        int buf=r[y][x];
        rep(i,2){
            int ny=y+roty[i],nx=x+rotx[i];
            int nb=buf;
            if(0<=ny&&ny<h&&0<=nx&&nx<w){
                if(t[ny][nx]=='#')if(t[y][x]!='#')nb++;
                if(chmin(r[ny][nx],nb))que.push({ny,nx});
            }
        }
    }
    cout<<r[h-1][w-1]<<endl;
}