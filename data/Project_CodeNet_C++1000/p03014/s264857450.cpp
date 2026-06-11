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
    return a*b/gcd(a, b);
}

int main()
{
    cout << fixed << setprecision(15);
    ll H, W;
    cin >> H >> W;

    vector<string> S(H);

    REP(i, H){
        cin >> S[i];
    }

    // cout << S[2][2] << endl;

    vector<vector<ll>> HC(H, vector<ll>(W,0));
    vector<vector<ll>> WC(H, vector<ll>(W,0));

    REP(i, H){
        REP(j, W){
            if(j == 0){
                if(S[i][j] == '#'){
                    HC[i][j] = 0;
                } 
                else{
                    HC[i][j] = 1;
                }
                continue;
            }
            // cout << S[i][j] << endl;
            if(S[i][j] == '#'){
                HC[i][j] = 0;
                // cout << "hello2";
            } 
            else{
                HC[i][j] = HC[i][j-1] + 1;
                // cout << "hello";
            }
        }
        for(ll j= W-1; j>=0; j--){
            // cout << HC[i][j] << endl;
            if(j == W-1) continue;
            if(HC[i][j] == 0) continue;

            HC[i][j] = max(HC[i][j], HC[i][j+1]);
        }
    }

    REP(i, W){
        REP(j, H){
            if(j == 0){
                if(S[j][i] == '#'){
                    WC[j][i] = 0;
                } 
                else{
                    WC[j][i] = 1;
                }
                continue;
            }
            if(S[j][i] == '#'){
                WC[j][i] = 0;
            } 
            else{
                WC[j][i] = WC[j-1][i] + 1;
            }
        }
        for(ll j= H-1; j>=0; j--){
            if(j == H-1) continue;
            if(WC[j][i] == 0) continue;

            WC[j][i] = max(WC[j][i], WC[j+1][i]);
        }
    }
    
    // デバッグ用
    // REP(i, H){
    //     REP(j, W){
    //         cout << WC[i][j];
    //     }
    //     cout << endl;
    // }

    ll ans = 0;

    REP(i, H){
        REP(j, W){
            ans = max(ans, HC[i][j] + WC[i][j]-1);
        }
    }
    cout << ans << endl;
    return 0;
}