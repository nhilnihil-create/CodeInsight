// 最大公約数
// a,bの最小公倍数(LCM)はa*b/GCD
/*
 * C言語のサンプルプログラム - Webkaru
 * - 入力した2つの自然数の最大公約数を求める -
 */
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素

int main(){
    int N;
    cin>>N;
    vector<vector<pair<int,int>>> s(N);
    rep(i,N){
        int A;
        cin>>A;
        rep(j,A){
            int x,y;
            cin>>x>>y;
            x--;
            s[i].emplace_back(x,y);
        }
    }
    int ans=0;
    rep(i,1<<N){
        int ii=i;
        bool b=true;
        int c=0;
        while(ii>0){
            if(ii&1){
                for(pair<int,int> p : s[c]){
                    b&= (((i>>p.F)&1)==p.S);
                }
            }
            ii=ii>>1;
            c++;
        }
        if(b) ans=max(ans,__builtin_popcount(i));
    }
    cout<<ans<<endl;
    return 0;
}