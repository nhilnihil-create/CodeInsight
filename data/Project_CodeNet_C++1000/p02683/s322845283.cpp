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
    lol n; cin >> n;
    lol m; cin >> m;
    lol x; cin >> x;

    int a[13][13];
    REP(i, n)
    {
        cin >> a[i][0];
        FOR(j, 1, m)
        {
            cin >> a[i][j];
        }
    }

    result = INF;

    for (int tmp = 0; tmp < (1 << 12); tmp++)
    {
        bool fl = true;
        bitset<12> s(tmp);  // 最大20個なので20ビットのビット列として扱う
        vector<lol> b(13);
        // ビット列の1のビットに対応する整数を選んだとみなして総和を求める
        for (int i = 0; i < n; i++) {
            if (s.test(i))
            {
                FOR(j, 0, m)
                {
                    b[j] += a[i][j];
                }
            }
        }
        //cout << "b[0] = " << b[0] << endl;
        FOR(i, 1, m)
        {
            if(b[i] < x)
            {
                fl = false;
                break;
            }
        }
        if(fl)
        {
            if(b[0] < result)
                result = b[0];
        }
        b.clear();
    }
    if(result == INF)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << result << endl;
    return 0;
}