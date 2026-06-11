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
    ll N, K;
    cin >> N >> K;

    vector<ll> A(N+1, 0);

    for(ll i=1; i<=N; i++){
        cin >> A[i];
    }

    vector<ll> S(N+1, 0);

    for(ll i=1; i<=N; i++){
        S[i] = S[i-1] + A[i]; 
    }

    vector<ll> B(N+1, 0);

    for(ll i=1; i<=N; i++){
        B[i] = ((S[i]-i)%K + K) % K;
    }

    // for(ll i=1; i<=N; i++){
    //     cout << B[i] << endl;
    // }

    map<ll, ll> M;
    ll ans = 0;

    for(ll i=1; i<=min(N,K); i++){
        ll temp = B[i];

        // if(temp == 0){
        //     ans++;
        //     continue;
        // }
        // もしもmapに入っていないなら
        if(M.count(temp) == 0){
            M[temp]++;
        }
        else{
            ans += M[temp];
            M[temp]++;
        }
        if(i < K){
            if(temp == 0) ans++;
        }   
    }

    for(ll i=2; i+K-1<=N; i++){
        // 一つ前の要素を消す
        M[B[i-1]]--;

        ll temp = B[i+K-1];

        // if(temp == 0){
        //     // ans++;
        //     continue;
        // }
        // もしもmapに入っていないなら
        if(M.count(temp) == 0){
            M[temp]++;
        }
        else{
            ans += M[temp];
            M[temp]++;
        }
        
    }

    cout << ans << endl;
    return 0;
}