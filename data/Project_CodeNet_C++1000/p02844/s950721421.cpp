#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// マクロ
// forループ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(ll)(b);i--)
// xにはvectorなどのコンテナ
#define ALL(x) (x)begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
// 出力
#define PRINT(x) cout<<(x)<<endl
#define PRINTA(x,n) REP(i,n)PRINT(x[i])
// 定数
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
// 略記
#define PB push_back
#define MP make_pair

int N;
string S;

int main() {
    cin >> N >> S;
    int ans = 0;
    REP(i, 10) {
        REP(j, 10) {
            REP(k, 10) {
                ll a[] = {i, j, k, 10};
                int ai = 0;
                REP(l, N) {
                    if (S[l] - '0' == a[ai]) ai++;
                }
                if (ai == 3) ans++; 
            }
        }
    }
    PRINT(ans);
    return 0;
}