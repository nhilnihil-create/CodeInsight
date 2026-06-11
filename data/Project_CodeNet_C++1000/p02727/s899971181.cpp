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

int main()
{
    lol result{0};
    lol x, y, an, bn, cn; cin >> x >> y >> an >> bn >> cn;
    vector<lol> a(an+2, INF), b(bn+2, INF), c(cn+2, INF);
    FOR(i, 1, an)
    {
        cin >> a[i];
    }
    FOR(i, 1, bn)
    {
        cin >> b[i];
    }
    FOR(i, 1, cn)
    {
        cin >> c[i];
    }
    a[0] = -1; b[0] = -1; c[0] = -1;
    sort(ALL(a));
    sort(ALL(b));
    sort(ALL(c));
    lol ci = cn, bi = bn + 1 - y, ai = an + 1 - x;
    while(ci != 0)
    {
        if(a[ai] < b[bi] && a[ai] < c[ci])
        {
            a[ai] = c[ci];
            ai++; ci--;
            //cout << c[ci] << endl;
        }
        else if(a[ai] >= b[bi] && b[bi] < c[ci])
        {
            b[bi] = c[ci];
            bi++; ci--;
            //cout << c[ci] << endl;
        }
        else
        {
            break;
        }
        
    }
    FOR(i, bn + 1 - y, bn)
    {
        result += b[i];
        //cout << i << ":" << b[i] << " ";
    }
    FOR(i, an + 1 - x, an)
    {
        result += a[i];
    }

    cout << result << endl;
    return 0;
}