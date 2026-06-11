#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) x.begin(),x.end() //sortなどの引数を省略したい
#define SIZE(x) ll(x.size()) //sizeをsize_tからllに直しておく
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define PB emplace_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define Umap unordered_map
#define Uset unordered_set

int main(){
    string s;
    cin >> s;
    vector<ll> ans(int(s.length()));
    char ex = 'R';
    ll tmp = 0;
    REP(i, int(s.length())){
        if(ex == s[i]) tmp++;
        else{
            if(ex == 'R'){
                ans[i-1] += tmp / 2 + (tmp%2);
                ans[i] += tmp / 2;
            }
            else{
                ans[i-tmp-1] += tmp / 2;
                ans[i-tmp] += tmp / 2 + (tmp%2);
            }
            // cout << "tmp: " << tmp << endl;
            ex = s[i];
            tmp = 1;
        }
    }
    ans[int(s.length())-tmp-1] += tmp / 2;
    ans[int(s.length())-tmp] += tmp / 2 + (tmp%2);
    REP(i, int(s.length())) cout << ans[i] << " ";
    return 0;
}