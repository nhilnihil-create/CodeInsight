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

vector<lol> anss(10, 0);

void bfs(lol n)
{
    queue<lol> a;
    REP(i, 9)
        a.push(i+1);
    lol nown = 9;
    while(nown <= n)
    {
        //cout << "*";
        lol now = a.front(); a.pop();
        string s = to_string(now);
        char ch = s[s.length()-1];
        lol chn = (lol)ch - (lol)'0';
        if(chn > 0)
        {
            string s1 = s + to_string(chn-1);
            nown++;
            anss.push_back(stoll(s1));
            a.push(stoll(s1));
        }
        string s2 = s + to_string(chn);
        nown++;
        anss.push_back(stoll(s2));
        a.push(stoll(s2));
        if(chn < 9)
        {
            string s3 = s + to_string(chn+1);
            nown++;
            anss.push_back(stoll(s3));
            a.push(stoll(s3));
        }
        if(nown > n)
            break;
    }
}

int main()
{
    lol result{0};
    lol n; cin >> n;
    REP(i, 9)
    {
        anss[i+1] = i + 1;
    }
    if(n <= 9)
        result = n;
    else
    {
        //cout << "あ" << endl;
        bfs(n);
        result = anss[n];
    }
    /*REP(i, n)
    {
        cout << anss[i+1] << " ";
    }
    cout << endl;*/
    

    cout << result << endl;
    return 0;
}