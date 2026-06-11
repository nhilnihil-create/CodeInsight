#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    int w,h;
    int dx[8]={1,1,1,0,-1,-1,-1,0},dy[8]={-1,0,1,1,1,0,-1,-1};
    while(cin>>w>>h,w||h){
        vector< vector<int> > field(h,vector<int>(w));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>field[i][j];
            }
        }
        int res=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(field[i][j]){
                    //cout<<i<<" "<<j<<endl;
                    queue<P> q;
                    field[i][j]=0;
                    q.push(P(i,j));
                    while(!q.empty()){
                        P p=q.front();q.pop();
                        for(int k=0;k<8;k++){
                            int nx=p.first+dx[k],ny=p.second+dy[k];
                            if(nx<0||h<=nx||ny<0||w<=ny) continue;
                            if(field[nx][ny]==0) continue;
                            field[nx][ny]=0;
                            q.push(P(nx,ny));
                        }
                    }
                    res++;
                }
            }
        }
        cout<<res<<endl;
    }
}