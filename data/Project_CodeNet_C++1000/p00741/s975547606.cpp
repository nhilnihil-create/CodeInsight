#include <iostream>
#include <algorithm>
#include <queue>
#include <array>
using namespace std;
typedef pair<int,int> P;

const array<int,8> dx={0,1,0,-1,1,1,-1,-1};
const array<int,8> dy={1,0,-1,0,1,-1,-1,1};
const int W=50;
const int H=50;

char M[H+1][W+1];

inline bool in_M(const int y,const int x){
    return (y>=0 && y<H && x>=0 && x<W);
}

void bfs(const int sy,const int sx){
    queue<P> que;

    que.push(P(sy,sx));
    M[sy][sx]='0';

    while(!que.empty()){
        P p=que.front();que.pop();

        for(int i=0;i<dx.size();i++){
            int ddy=p.first+dy[i],ddx=p.second+dx[i];
            if(in_M(ddy,ddx) && M[ddy][ddx]=='1'){
                que.push(P(ddy,ddx));
                M[ddy][ddx]='0';
            }
        }
    }
}

void solve(){
    int sum;
    int w,h;

    while(cin>>w>>h,w|h){
        cin.ignore();
        sum=0;

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>M[i][j];
                cin.ignore();
            }
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(M[i][j]=='1'){
                    bfs(i,j);
                    sum++;
                }
            }
        }

        cout<<sum<<endl;
    }
}

int main(){
    solve();
    return 0;
}


        