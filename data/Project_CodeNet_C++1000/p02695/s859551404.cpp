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

    int N,M,Q;
    vector<int> a,b,c,d;
    ll ans=0;
void dp(vector<int> v,int i){
    if(i==N){
        // rep(j,N) cout<<v[j]<<",";
        // cout<<endl;
        ll s=0;
        rep(j,Q){
            if(v[b[j]]-v[a[j]]==c[j]) s+=d[j];
        }
        ans=max(ans,s);
        return;
    }
    for(int j=(i==0? 1 : v[i-1]);j<=M;j++){
        v[i]=j;
        dp(v,i+1);
    }
}

int main(){
    cin>>N>>M>>Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    rep(i,Q){ 
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--;
        b[i]--;
        c[i];
        d[i];
    }
    vector<int> v(N);
    dp(v,0);
    cout<<ans<<endl;
    return 0;
}


