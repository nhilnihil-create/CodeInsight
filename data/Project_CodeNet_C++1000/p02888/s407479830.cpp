#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000005 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素

int main(){
    ll N;
    cin>>N;
    vector<int> L(N);
    rep(i,N) cin>>L[i];
    ll ans=0;
    sort(L.begin(),L.end());
    for(int a=2;a<N;a++){
        for(int b=1;b<a;b++){
            int c=upper_bound(L.begin(),L.begin()+b,L[a]-L[b])-L.begin();
            ans+=max(b-c,0);
        }
    }
    cout<<ans<<endl;
    return 0;
}