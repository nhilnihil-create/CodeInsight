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
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
//最大値最小値
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

void rec(lol& n, int i, lol& result);
int che;

int main()
{
    lol result{0};
    lol n; cin >> n;
    lol m = n;
    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    int sqr = sqrt(n);
    FOR(i, 2, sqr)
    {
        if(n < i)
            break;
        //n = m;
        lol a{0};
        rec(n, i, a);
        //cout << n << endl;
        if(a > 0)
        {
            for(int j = 1; j*(j + 1) <= 2*a; j++)
            {
                result++;
            }
            //cout << result << endl;
        }
    }
    //cout << che << " " << result << " " << pow(che, 2) << " " << m << endl;
    /*if(result == 1 && pow(che, 2) != m)
        result++;*/
    if(n != 1)
        result++;

    cout << result << endl;
    return 0;
}

void rec(lol& n, int i, lol& result)
{
    if(n%i != 0)
        return;
    if(n%i == 0)
    {
        che = i;
        result++;
        n /= i;
        rec(n, i, result);
    }
}