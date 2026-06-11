#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
#include<map>
 
 
using namespace std;
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007


int N;
int A[1005][1005];

int matchNum(int i,int j){//0~M-1
    if(i>j)return matchNum(j,i);
    if(i==0)return j-i-1;
    else return (N-1+N-i)*i/2+(j-i)-1;
}

int dist[10005*10005/2];
int start[10005*10005/2];
int ifvis[10005*10005/2];
vector<int> edges[1005*1005/2];

int dfs(int v) {//vから深さ優先探索を始める
    if (start[v]) {
        if (!ifvis[v]) return -1;//戻ってきてしまったら閉路が存在する
        return dist[v];//二回呼び出しちゃった時用
    } else {
        start[v] = true;
        int k = 0;
        for (int e=0;e<edges[v].size();e++) {
            int nxt = dfs(edges[v][e]);//辺をたどっていく
            if (nxt == -1) return -1;
            else k = max(k, nxt);
        }
        ifvis[v] = true;
        dist[v] = k + 1;
        return dist[v];
    }
}

signed main(){
    scanf("%lld",&N);
    rep(i,N)rep(j,N-1){scanf("%lld",&A[i][j]);A[i][j]--;}
    //試合を頂点に見立てて辺を貼る
    const int M=N*(N-1)/2;
    rep(i,N)rep(j,N-2){
        int first=matchNum(i,A[i][j]);
        int second=matchNum(i,A[i][j+1]);
        edges[first].pb(second);
    }
    //深さ優先探索で閉路があるかどうかと最長パス長を調べる
    int ans=0;
    rep(i,M)dist[i]=-1;//初期化
    rep(i,M){//各頂点を始点として深さ優先探索
        int d=dfs(i);
        if (d == -1) {//閉路が見つかった場合
            ans = -1;
            break;
        } else {//見つからなかった場合
            ans = max(ans, d);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
