#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int mod = 1000000007;
const int inf = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

int tx[2] = {0, 1};
int ty[2] = {1, 0};

struct route{
    int x, y, num;
};

int main(){
    int h, w;
    cin >> h >> w;
    char maze[h][w];
    rep(i,h)rep(j,w) cin >> maze[i][j];
    int ch[h][w];
    rep(i,h)rep(j,w) ch[i][j] = inf;
    ch[0][0] = 0;
    queue<route> q;
    route e = {0,0,0};
    q.push(e);
    while(!q.empty()){
        route p = q.front();
        q.pop();
        int x = p.x;
        int y = p.y;
        int num = p.num;
        if(ch[x][y]<num) continue;

        rep(i,2){
            int nx = x + tx[i];
            int ny = y + ty[i];
            if(nx>=0&&nx<h&&ny>=0&&ny<w){
                int j = num;
                if(maze[x][y]!=maze[nx][ny]) j++;
                if(ch[nx][ny] > j){
                    ch[nx][ny] = j;
                    route r = {nx, ny, j};
                    q.push(r);
                }
            }
        }

    }
    cout << (ch[h-1][w-1]+1)/2 + (maze[0][0]=='#'&&maze[h-1][w-1]=='#'?1:0) << endl;
}