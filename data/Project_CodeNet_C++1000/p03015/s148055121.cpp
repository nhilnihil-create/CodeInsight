#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

constexpr ll mod = 1e9 + 7;

int main(){
    string L;
    cin >> L;

    VVL dp(L.size()+10, VL(2, 0));
    // dp[i][0] : 左からi桁目まで決めたときの(a, b)の組み合わせの数（exact := a+b == L)
    // dp[i][1] : 同上（smaller）

    // Lの先頭は1なので．
    dp[0][0] = 2; // (0, 1), (1, 0)
    dp[0][1] = 1; // (0, 0)

    // i = 1を考えると，
    // L[i] = 0のとき，
    // (0, 1) -> (00, 10), x(00, 11), x(01, 10), x(01, 11)
    // (0, 0) -> (01, 00), x(01, 01), (00, 00), (00, 01)
    // (1, 0) -> (10, 00), x(10, 01)
    // の遷移が考えられるが，まず，b=11はLより大きくなるので却下
    // また，(01, 10)もLより大きくなるので不可

    // まず，両方に1をつける操作は不可
    // L_i = 0/１ のとき，smaller は両方に1以外なら，なんでもたいして良い：3通り
    // L_i = 0 のとき，exactは末尾に0をつけることしかできない．
    // L_i = 1 のとき，exactは末尾に1をつけて，exactをKeepする2通りと，aかbの末尾に0をつけて，smallerに落とす1通りがある．

    rep(i, 1, L.size()){

        // smaller -> smaller
        dp[i][1] = 3 * dp[i-1][1];
        dp[i][1] %= mod;

        // exact -> smaller
        if(L[i] == '1'){
            dp[i][1] += dp[i-1][0];
            dp[i][1] %= mod;
        }

        // exact -> exact
        if(L[i] == '1'){
            dp[i][0] = 2 * dp[i-1][0];
            dp[i][0] %= mod;
        }else{
            dp[i][0] = dp[i-1][0];
        }
    }

    ll ans = dp[L.size()-1][0] + dp[L.size()-1][1];
    ans %= mod;

    cout << ans << endl;
    return 0;
}