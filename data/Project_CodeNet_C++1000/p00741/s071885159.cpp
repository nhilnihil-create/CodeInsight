#include <iostream>
#include<vector>
using namespace std;

int w,h;
int c[50][50];
vector<vector<int> > visited;
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,-1,-1,-1,0,1,1,1};

bool dfs(int x,int y){
    if(visited[x][y]) return false;
    visited[x][y]=1;

    for(int d=0;d<8;d++){
        int i=x+dx[d];
        int j=y+dy[d];
        if(0<=i&&i<h&&0<=j&&j<w){
            if(c[i][j]){
                dfs(i,j);
            }  
        }
    }
    return true;
}

int solve(int w,int h){

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>c[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(c[i][j]){
                cnt+=dfs(i,j);
            }
        }
    }
    cout<<cnt<<endl;
}

int main(){
    visited.assign(50,vector<int>(50,0));
    while(1){
        cin>>w>>h;
        if(!(w))break;

        solve(w,h);
        visited.assign(50,vector<int>(50,0));
    }
    
    return 0;
}
