#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

#define MP make_pair
typedef pair<int,int> pii;

constexpr int dx[4]={1,0,-1,0};
constexpr int dy[4]={0,1,0,-1};

int main(){
    int W,H;
    while(cin>>W>>H){
        if(W==0&&H==0) return 0;

        vector<string> t(H);
        vector<vector<bool>> used(H,vector<bool>(W,false));
        for(int i=0;i<H;i++) cin>>t[i];

        int sx,sy;
        for(int i=0;i<H;i++) for(int j=0;j<W;j++) if(t[i][j]=='@'){
            sx = i;
            sy = j;
        }
        used[sx][sy]=true;

        queue<pii> que;
        que.push(make_pair(sx,sy));

        while(que.size()!=0){
            pii p = que.front();
            que.pop();

            int x = p.first;
            int y = p.second;

            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<H && ny>=0 && ny<W && t[nx][ny]!='#' && used[nx][ny]==false){
                    used[nx][ny] = true;
                    que.push(MP(nx,ny));
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<H;i++) for(int j=0;j<W;j++) if(used[i][j]==true) cnt++;
        cout << cnt << endl;
    }
}