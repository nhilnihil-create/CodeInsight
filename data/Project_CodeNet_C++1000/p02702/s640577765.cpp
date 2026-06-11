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
    int mod=2019;
    string S;
    cin>>S;
    int n;
    n=S.size();
    reverse(S.begin(),S.end());
    map<int,int> M;
    int mul=1;
    int pre=0;
    M[0]++;
    rep(i,n){
        int t=pre+(S[i]-'0')*mul;
        t%=mod;
        M[t]++;
        mul=(mul*10)%mod;
        pre=t;
 //       cout<<t<<" ";
    }
//    cout<<endl;
    ll ans=0;
    for(pair<int,int> p : M){
        ans+=p.S*(p.S-1)/2;
    }
    cout<<ans<<endl;
}


