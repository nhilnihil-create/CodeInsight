#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) x.begin(),x.end() //sortなどの引数を省略したい
#define SIZE(x) ll(x.size()) //sizeをsize_tからllに直しておく
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define Umap unordered_map
#define Uset unordered_set

int main(){
    ll n, q, a, b, p, x;
    cin >> n >> q;
    vector<vector<ll>> g(n+1);
    vector<ll> score(n+1), dist(n+1, -1);
    REP(i, n-1){
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    REP(i, q){
        cin >> p >> x;
        score[p] += x;
    }
    queue<int> que;
    int start = 1;
    que.push(start);
    dist[start] = score[1];
    while(que.empty() != true){
        int v = que.front();
        que.pop();
        for(int y : g[v]){
            if(dist[y] == -1){
                dist[y] = dist[v] + score[y];
                que.push(y);
            }
        }
    }
    REP(i, n) cout << dist[i+1] << " ";
    return 0;
}