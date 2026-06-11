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

int main()
{
    int N;
    int K;

    cin >> N >> K;

    int e = (N-1)*(N-2)/2 - K;
    // 構成できないとき
    if(e < 0){
        cout << -1 << endl;
        return 0;
    }

    cout << e + (N-1) << endl;
    // スターグラフの作成
    for(int i=2; i<=N; i++){
        cout << 1 << " " << i << endl;
    }

    if(e == 0) return 0;
    int count = 0;
    
    // ショートカット辺の追加
    for(int i=2; i<=N-1; i++){
        for(int j=i+1; j<=N; j++){
            cout << i << " " << j << endl;
            count++;
            if(count == e) return 0;
        }
       
    }
    return 0;
}