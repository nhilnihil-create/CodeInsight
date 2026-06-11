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
    ll N, M;
    string S;

    cin >> N >> M;
    cin >> S;

    ll now = N;
    vector<ll> ans;
    while(now != 0 && now != -1){
        // もしも残りがM以下なら終了
        if(now <= M){
            ans.push_back(now);
            now = 0;
            break;
        }
        bool check = false;
        for(ll i=M; i>=1; i--){
            // もしも移動できるなら
            if(S[now-i] == '0'){
                now = now - i;
                ans.push_back(i);
                check = true;
                break;
            }
        }
        // もしも動けなかったとき
        if(check == false){
            cout << -1 << endl;
            return 0;
        }
    }

    reverse(ans.begin(), ans.end());

    ll L = ans.size();
    REP(i, L){
        if(i == L-1){
            cout << ans[i] << endl;
        }
        else{
            cout << ans[i] << " ";
        }
    }
    return 0;
}