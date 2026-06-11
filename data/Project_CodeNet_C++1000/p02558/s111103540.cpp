#include<atcoder/all>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>

#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))
#define dump(x)  cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long

const int INF = 1e18;
const int MOD = 1e9+7;
//const lint LINF = 1e18;
const double eps = 0.000000001;//もとの値の10^(-16)まで

using namespace std;
using namespace atcoder;

//typedef pair<int, int> P;
//priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
//cout << fixed << setprecision(10) << ans << endl;
//int gcd(int a,int b){return b?gcd(b,a%b):a;}


// dsu d(int n) // n頂点(頂点番号 0 ~ n-1) 0辺の無向グラフの作成。グラフ名をdとして使うときは "dsu d(n);"
// d.merge(int a, int b) // 辺(a,b)の追加
// bool d.same(int a, int b) // 頂点a,bが連結かどうかを返す
// int d.size(int a) // 頂点aの属する連結成分のサイズを返す
// vector<vector<int>> d.groups() // グラフを連結成分に分け、その情報を返す。返り値は「「一つの連結成分の頂点番号のリスト」のリスト」。


signed main(){
    int n,q;
    cin >> n >> q;
    dsu d(n);

    REP(i,q){
        int t1,u1,v1;
        cin >> t1 >> u1 >> v1;
        if(t1==0){
            d.merge(u1,v1);
        }
        else{
            cout << d.same(u1,v1) << endl;
        }
    }
    

    



    return 0;
}
