#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define MOD2 1494318097
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define nl '\n'
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 105;

int R,C,dis[maxn][maxn],m[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
bool vis[maxn][maxn],in[maxn][maxn];
char arr[maxn][maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    for(int i=1; i<=R; i++)
        for(int k=1; k<=C; k++)
            cin >> arr[i][k];
    memset(dis,0x3f,sizeof dis);
    queue<pii> q;
    dis[0][1] = 0;
    vis[0][1] = true;
    arr[0][1] = '.';
    q.push(mp(0,1));
    while(q.size()){
        int x = q.front().first, y = q.front().second; q.pop();
        for(int i=0; i<4; i++){
            int nx = x+m[i][0], ny = y+m[i][1], cc = dis[x][y]+(arr[x][y]!=arr[nx][ny]);
            if(nx >= 1 && ny >= 1 && nx <= R && ny <= C && dis[nx][ny] > cc){
                dis[nx][ny] = cc;
                if(!in[nx][ny])
                    in[nx][ny] = true, q.push(mp(nx,ny));
            }
        }
    }
    cout << (dis[R][C]+1)/2 << nl;
}