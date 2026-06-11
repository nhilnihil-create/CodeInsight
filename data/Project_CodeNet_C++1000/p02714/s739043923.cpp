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
#define R 10000
#define G 10001
#define B 10002

int main()
{
    lol r{0}, g{0}, b{0};
    lol result{0};
    lol n; cin >> n;
    vector<int> a(n+2, 0);
    a[0] = -1;
    a[n+1] = -1;
    FOR(i, 1, n)
    {
        char ch; cin >> ch;
        if(ch == 'R')
        {
            //cout << "r=" << r << endl;
            r++;
            a[i] = 1;
        }
        else if(ch == 'G')
        {
            //cout << "g=" << g << endl;
            g++;
            a[i] = 2;
        }
        else
        {
            b++;
            a[i] = 3;
        }
        
    }
    result = r*g*b;
    FOR(i, 1, n)
    {
        lol j = 1;
        while(a[i-j] != -1 && a[i+j] != -1)
        {
            //cout << a[2] << endl << a[3] << endl << a[4] << endl;
            if((a[i-j] != a[i+j]) && (a[i-j] != a[i]) && (a[i+j] != a[i]))
                result--;
            j++;
        }
    }
    

    cout << result << endl;
    return 0;
}