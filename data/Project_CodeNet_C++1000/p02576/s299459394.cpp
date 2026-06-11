#include <bits/stdc++.h>

#pragma region Macro
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define SORT(v) sort(v.begin(), v.end())
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define vi vector<int>
#define vvi vector<vector<int>>
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#pragma endregion

void solve(){
    #define int ll
    int n, x, t;
    cin >> n >> x >> t;
    cout << t*((n+x-1)/x) <<endl;
    // ここに処理を記述
    // コンパイル時はエイリアス「gpp」--> c++17でコンパイル

}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);//小数点の桁数

    solve();
    return 0;
}