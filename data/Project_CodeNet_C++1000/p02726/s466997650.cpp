#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int N, X, Y;
int res = 0;
vector<vector<int>> Graph(2010, vector<int>());
vector<vector<int>> dp(2010, vector<int>(2010, 0));
vector<vector<int>> circular_list(2010, vector<int>(2,0));
vector<int> num_dist;


/*循環リストの作成*/
void make_cl(int x, int y){
    for(int i = x; i <= y; i++){
        if(i == y) circular_list[i][0] = x;  //forward
        else circular_list[i][0] = i+1;
        if(i == x) circular_list[i][1] = y;  //back
        else circular_list[i][1] = i-1;
    }
    return ;
}


/*循環リスト域の頂点間の最短距離票を作成*/
void make_dl(int i, int x, int y){
    int diff = y-x;
    if(diff & 1){   //対頂点は1つ
        int ver_p = (x+y+1)/2 + (i-x);
        if(ver_p > y) ver_p = ver_p % (y+1) + x;  //形状：環⇒修正

        int f, b; f = b = ver_p;  //対頂点を格納
        int fd, bd; fd = bd = (y-x+1)/2;  //対頂各同士の距離
        while(f != i){
            dp[i][f] = dp[f][i] = fd--;
            f = circular_list[f][0];
        }
        
        while(b != i){
            dp[i][b] = dp[b][i] = bd--;
            b = circular_list[b][1];
        }

    }else{
        int ver_p1 = (x+y)/2+1+(i-x);    //進行対頂点
        int ver_p2 = (x+y)/2+(i-x);    //後退対頂点
        if(ver_p1 > y) ver_p1 = ver_p1 % (y+1) + x;
        if(ver_p2 > y) ver_p2 = ver_p2 % (y+1) + x;

        int fd, bd; fd = bd = (y-x)/2;
        while(ver_p1 != i){
            dp[i][ver_p1] = dp[ver_p1][i] = fd--;
            ver_p1 = circular_list[ver_p1][0];
        }

        while(ver_p2 != i){
            dp[i][ver_p2] = dp[ver_p2][i] = bd--;
            ver_p2 = circular_list[ver_p2][1];
        }
    }

    return ;
}


int main(){
    cin >> N >> X >> Y;
    num_dist.assign(N, 0);  //最大距離まで

    Graph[X].pb(Y); Graph[Y].pb(X);  //特別の一辺
    for(int i = 1; i <= N-1; i++){
        Graph[i].pb(i+1);
        if(X <= i && i+1 <= Y) Graph[i+1].pb(i);
    }

    make_cl(X, Y);
    for(int i = X; i <= Y; i++) make_dl(i, X, Y);

    for(int i = 1; i <= N-1; i++){
        for(int j = i+1; j <= N; j++){
            if(i <= X){
                if(j <= X) ++num_dist[j-i];
                else if(X < j && j <= Y) ++num_dist[(X-i)+dp[X][j]];
                else if(Y < j) ++num_dist[(X-i)+dp[X][Y]+(j-Y)];
            }else if(X < i && i <= Y){
                if(X < j && j <= Y) ++num_dist[dp[i][j]];
                else if(Y < j) ++num_dist[dp[i][Y]+(j-Y)];
            }else if(Y < i) ++num_dist[j-i];

        }
    }

    for(int i = 1; i < N; i++) cout << num_dist[i] << endl;
    return 0;
}



