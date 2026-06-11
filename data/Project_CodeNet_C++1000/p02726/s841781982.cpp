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
    int N,X,Y;
    cin>>N>>X>>Y;
    X--;
    Y--;
    vector<int> A(N);
    rep(i,N-1){
        for(int j=i+1;j<N;j++){
            int d=min(j-i, abs(j-X)+1+abs(i-Y));
            d=min(d, abs(j-Y)+1+abs(i-X));
            A[d]++;
        }
    }
    for(int i=1;i<N;i++) cout<<A[i]<<endl;
    return 0;
}
