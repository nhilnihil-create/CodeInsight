#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<climits>//long long型の最大値(LLONG_MAX)など
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

using namespace std;
typedef long long ll;
typedef long double lb;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)


int main() {
    ll A,B,M;
    cin >> A >> B >> M;
    vector<ll> a(A),b(B);
    rep(i,A){
        cin >> a[i];
    }
    rep(i,B){
        cin >> b[i];
    }

    vector<tuple<ll,ll,ll>> waribiki(M);
    rep(i,M){
        ll x,y,c;
        cin >> x >> y >> c;
        waribiki[i] = make_tuple(x,y,c);
    }
    
    ll ans = LLONG_MAX;

    rep(i,M){
        ll result = a[get<0>(waribiki[i])-1] + b[get<1>(waribiki[i])-1] - get<2>(waribiki[i]);
        ans = min(ans,result);
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ans = min(ans,a[0]+b[0]);
    cout << ans << endl;

}
