#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
const int INF=1000000;
int d[1005][1005];
int dx[4]= {1,0,-1,0};
int dy[4]= {0,1,0,-1};
char s[1005][1005];
int m,n,k;
//int sx,sy,gx,gy;
typedef pair <int,int >P;
P aim[15];
int isd(char ch)
{
    return ch>='0'&&ch<='9'?1:0;
}
int bfs(int sx,int sy,int gx,int gy)
{
    queue<P> que;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            d[i][j]=INF;
//            cout <<d[i][j]<<endl;
        }
    }
    que.push(P(sx,sy));
    d[sx][sy]=0;
    while(que.size())
    {

        P p=que.front();
        que.pop();
        if(p.first==gx&&p.second==gy)
        {
            break;
        }
        for(int i=0; i<4; i++)
        {
            int nx=p.first+dx[i];
            int ny=p.second+dy[i];
//            cout << nx << ":" << ny << endl;
//            cout << que.size()<<" "<<m<<" "<<n<<endl;
            if( nx>=0&&nx<m
                    &&ny>=0&&ny<n
                    &&s[nx][ny]!='X'
                    &&d[nx][ny]==INF)
            {

                que.push(P(nx,ny));

                d[nx][ny]=d[p.first][p.second]+1;
            }
        }
    }
    return d[gx][gy];
}
int main()
{
    cin >> m >> n >> k;
    int sum = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> s[i][j];
            if(s[i][j]=='S')
            {
                aim[0].first=i;
                aim[0].second=j;
//                cout << i <<" "<< j <<endl;
            }
            if(isd(s[i][j]))
            {
                aim[s[i][j]-'0'].first=i;
                aim[s[i][j]-'0'].second=j;
//                cout << i << " "<<j <<endl;
            }

        }


    }
    for(int i=0; i<k; i++)
    {
        int steep=bfs(aim[i].first,aim[i].second,aim[i+1].first,aim[i+1].second);
        sum+=steep;
//            cout << steep <<endl;
    }
    cout << sum <<endl ;
}