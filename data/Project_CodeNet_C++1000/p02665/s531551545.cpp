// c
#include <bits/stdc++.h>
#include <string>
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
#define S second　//pairの二つ目の要素


int main(){
    int n;
    cin>>n;
    ll a[n+1],b[n+1],aa=0;
    rep(i,n+1){
        cin>>a[i];
        aa+=a[i];
    }
    b[0]=1-a[0];
    aa-=a[0];
    for(int i=1;i<n+1;i++){
        aa-=a[i];
        b[i]=min(2*b[i-1]-a[i],aa);
        if(i!=n && b[i]<=0){
        cout<<"-1"<<endl;
        return 0;
        }
    }
    if(b[n]!=0){
        cout<<"-1"<<endl;
        return 0;
    }
    ll ans=0;
    rep(i,n+1) ans+=a[i]+b[i];
    cout<<ans<<endl;
    return 0;
}