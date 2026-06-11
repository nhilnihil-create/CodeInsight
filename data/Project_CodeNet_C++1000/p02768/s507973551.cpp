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

lol modPow(lol a, lol n, lol p)
{
    if(n == 0) return 1;
    if(n == 1) return a%p;
    if(n%2 == 1) return (a*modPow(a, n-1, p))%p;
    lol t = modPow(a, n/2, p);
    return (t*t)%p;
}

int main()
{
    lol result{1};
    lol n, a, b; cin >> n >> a >> b;
    result = modPow(2, n, MOD)-1;
    lol ac{1}, bc{1}, an{1}, bn{1};
    FORD(i, a, 1)
        ac = (ac*i)%MOD;
    FORD(i, b, 1)
        bc = (bc*i)%MOD;
    FORD(i, n, n-a+1)
        an = (an*i)%MOD;
    FORD(i, n, n-b+1)
        bn = (bn*i)%MOD;
    lol nCa = (an*modPow(ac, MOD-2, MOD))%MOD;
    lol nCb = (bn*modPow(bc, MOD-2, MOD))%MOD;
    result = result - nCa - nCb;
    while(result < 0) result += MOD;

    cout << result << endl;
    return 0;
}