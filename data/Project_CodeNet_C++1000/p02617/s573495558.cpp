//
//  main.cpp
//  ABC173F
#include <iostream>
#include<vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    ll v=0;
    ll e=0;
    // Sに含まれる頂点の数
    for(ll i=1;i<=n;i++){ // 3*1+2*2+1*3 = for(int i=1,i<=n,i++) i*(n-i+1)
        v+=i*(n-i+1);
    }
    // Sに含まれる辺が使われる回数
    rep(i,n-1){
        ll a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        e+=a*(n-b+1); // 辺(a-b)が使われる回数
        // a以下の頂点数、b以上n以下の頂点数の積の和
        // 1-3が使われるのは頂点1と頂点3が選ばれたときの1回
        // 2-3が使われるのは頂点1または2と頂点3が選ばれた時の2回
    }
    // 答えは頂点の数の合計ー辺の数の合計
    cout<<v-e<<endl;
    return 0;
}
//   S          L,R     連結成分数   Sに含まれる頂点の数 Sに含まれる辺の数
//  {1}         1,1         1           1           0
//  {1,2}       1,2         2           2           0
//  {1,2,3}     1,3         1           3           2
//  {2}         2,2         1           1           0
//  {2,3}       2,3         1           2           1
// {3}          3,3         1           1           0
//                          7     =    10      -    3
