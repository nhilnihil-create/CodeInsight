#include <bits/stdc++.h>
using namespace std;
typedef long long lol;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(lol i=0;i<lol(n);i++)
#define REPD(i,n) for(lol i=n-1;i>=0;i--)
#define FOR(i,a,b) for(lol i=a;i<=lol(b);i++)
#define FORD(i,a,b) for(lol i=a;i>=lol(b);i--)
#define VL vector<lol>
//xにはvectorなどのコンテナ
#define ALL(x) x.begin(),x.end() //sortなどの引数を省略したい
#define SIZE(x) lol(x.size()) //sizeをsize_tからllに直しておく
//定数
#define PI 3.1415926535897932385 //pi
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
//最大値最小値
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

lol dp[1005][10005], n;
lol a[1005], b[10005];

lol f(lol idx, lol hp)
{
    if(hp <= 0) return 0;
    if(idx > n) return INF;
    lol *sol = &dp[idx][hp];
    if(*sol != -1) return *sol;
    return *sol = min(f(idx+1, hp), f(idx, hp - a[idx])+b[idx]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    lol result{0};
    lol h; cin >> h >> n;
    FOR(i, 1, n)
    {
        cin >> a[i] >> b[i];
    }
    memset(dp, -1, sizeof(dp));
    result = f(1, h);

    cout << result << '\n';
    return 0;
}