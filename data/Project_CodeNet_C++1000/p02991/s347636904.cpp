#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


vector<bool> seen;  // 訪問済みの点
vector<ll> dist;

int main()
{
    int N, M;
    cin >> N >> M;

    // グラフ
    Graph G(3*N);

    REP(i, M){
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1 + N);
        G[a-1 + N].push_back(b-1 + 2*N);
        G[a-1 + 2*N].push_back(b-1);
    }

    int S, T;
    cin >> S >> T;

    vector<int> dist(3*N, -1);
    queue<int> que;

    dist[S-1] = 0;
    que.push(S-1);

    while(!que.empty()){
        int p;
        p = que.front();
        que.pop();

        for(int next :G[p]){
            // もし次のノードが訪問済みなら処理を飛ばす
            if(dist[next] != -1) continue;

            dist[next] = dist[p] + 1;
            que.push(next);
        }
    }
    
    if(dist[T-1] == -1){
        cout << -1 << endl;
    }
    else{
        cout << dist[T-1]/3 << endl;
    }
    return 0;
}