#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rp(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define all_acc(x) (x).begin(), (x).end(), 0LL
#define int long long
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool { return abs(i) < abs(j); });
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using ll = long long;
double pi=3.14159265359;

//出力するよ
void output_tate(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        //if (i != 0)
        //    cout << " ";
        cout << s[i]<<endl;
    }
    //cout << endl;
}

void output_yoko(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (i != 0)
            cout << " ";
        cout << s[i];//<<endl;
    }
    cout << endl;
}
int MOD = pow(10, 9) + 7;

//幅優先探索
//disは各座標への距離。行けない場合は-1にしている。
//chaは各座標の情報。文字で格納している。'.'はすすめる。'#'は壁(黒)。
//sはスタートの座標
//gはゴールの座標
vector<vector<int>> bfs(vector<vector<int>> dis,vector<vector<char>>cha,pair<int,int>s,pair<int,int>g){
    int h=dis.size();
    int w=dis.at(0).size();

    queue<pair<int,int>> Q;
    Q.push(s);
    dis.at(s.first).at(s.second)=0;
    if(cha[0][0]=='#') dis[0][0]=1;
    else dis[0][0]=0;

    while(!Q.empty()){
        int y,x;//今の座標
        y=Q.front().first; x=Q.front().second;
        Q.pop();

        //今回は後ろには戻らない。というか、0,0スタートなら戻る必要無さそう。
        int dy[4]={1,0,-1,0};
        int dx[4]={0,1,0,-1};
        for(int i=0;i<2;i++){
            //ey,exは変更後の座標。csは変える候補の値。
            int ey=y+dy[i];
            int ex=x+dx[i];
            int cs;
            //範囲外はスルー
            if(ex<0||ey<0||ex>=w||ey>=h) continue;
            //白から黒へ移るときにカウントが１増える
            if(cha[y][x]=='.' && cha[ey][ex]=='#') cs=dis[y][x]+1;
            else cs=dis[y][x];
            
            //未探索か、候補値の方が小さい場合、変更して変更先をキューに打ち込む
            if(dis[ey][ex]==-1 || cs<dis[ey][ex]){
                Q.push({ey,ex});
                dis[ey][ex]=cs;
            }
        }
    }

    return dis;
}

signed main() {
    int h,w; cin>>h>>w;
    vector<vector<char>> grid(h,vector<char>(w));
    vector<vector<int>> dis(h,vector<int>(w,-1));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++) cin>>grid[i][j];
    }

    dis=bfs(dis,grid,make_pair(0,0),make_pair(h-1,w-1));

    cout<<dis[h-1][w-1]<<endl;
}
