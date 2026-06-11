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

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a/gcd(a, b) * b;
}

int main()
{
    cout << fixed << setprecision(15);
    ll N;
    cin >> N;

    vector<queue<ll>> A(N);

    REP(i, N){
        REP(j, N-1){
            ll a;
            cin >> a;
            A[i].push(a-1);
        }
    }

    ll ans = 0;
    ll total = N*(N-1)/2;
    bool check = true;
    while(total>0 && check){
        vector<bool> B(N, false);

        check = false;
        REP(i, N){
            // もう全ての試合が終わっているとき
            if(A[i].empty()) continue;
            
            // 自分が今日すでに試合済みのとき
            if(B[i]) continue;

            // 相手が今日すでに試合済みのとき
            if(B[A[i].front()]) continue;
            
            // 次の試合相手と両思いのとき
            if(A[A[i].front()].front() == i){
                // 試合を抜き出しで今日を試合済みに
                A[A[i].front()].pop();
                B[A[i].front()] = true;
                A[i].pop();
                B[i] = true;

                // 総試合数のカウントを引く 
                total--;

                // 今日試合が行われたことのチェック
                check = true;
            }
        }
        ans++;
        // 1試合も行えなかったとき
        if(check == false){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}