#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素


int main(){
    int K,N;
    cin>>K>>N;
    vector<int> A(N);
    rep(i,N) cin>>A[i];
    int mav=0;
    rep(i,N-1) mav=max(mav,A[i+1]-A[i]);
    mav=max(mav,A[0]+K-A[N-1]);
    cout<<K-mav<<endl;
    return 0;
}
