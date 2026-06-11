#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define INF 100000000
int main(void){
    int h,w,n,ans=0;
    pair<int,int> start;
    cin>>h>>w>>n;
    vector<string>field(h+2,string(w+2,'X'));
    vector<vector<int>>d(h+2,vector<int>(w+2,0));
    vector<pair<int,int>>goal(n);
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    for(int i=1;i<h+1;i++){
        for(int j=1;j<w+1;j++){
            cin>>field[i][j];
            if(field[i][j]=='S'){
                start.first=j;
                start.second=i;
            }else if(field[i][j]!='.'&&field[i][j]!='X'){
                goal[(int)(field[i][j]-'1')].first=j;
                goal[(int)(field[i][j]-'1')].second=i;
            }
        }
    }
    for(int i=0;i<n;i++){
        queue<pair<int,int>> que;
        for(int j=0;j<h+2;j++){
            for(int k=0;k<w+2;k++){
                d[j][k]=INF;
            }
        }
        que.push(pair<int,int>(start.first,start.second));
        d[start.second][start.first]=0;
        while(que.size()){
            pair<int,int> p=que.front();
            que.pop();
            if((p.first==goal[i].first)&&(p.second==goal[i].second)){
                break;
            }
            for(int j=0;j<4;j++){
                int nx=p.first+dx[j];
                int ny=p.second+dy[j];
                if(field[ny][nx]!='X'&&d[ny][nx]==INF){
                    que.push(pair<int,int>(nx,ny));
                    d[ny][nx]=d[p.second][p.first]+1;
                }
            }
        }
        ans+=d[goal[i].second][goal[i].first];
        start.first=goal[i].first;
        start.second=goal[i].second;
    }
    cout<<ans<<endl;
}