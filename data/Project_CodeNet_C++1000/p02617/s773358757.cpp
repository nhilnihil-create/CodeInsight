#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;

#define rep(i,N) for(int i=0;i<(int)(N);++i)
#define rrep(i,N) for(int i=(int)(N)-1;i>=0;--i)
#define debug(x) cout<<#x<<"="<<x<<endl;
constexpr int MOD=1000000007;
constexpr ll INF=(1LL<<61)-1;
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> void fail(T v){cout << v << endl;exit(0);}
//template end

void solve(){
    int N;cin>>N;
    ll res=0;
    rep(i,N-1){
        int u,v;cin>>u>>v;u--;v--;
        if(u>v)swap(u,v);
        res-=(u+1LL)*(N-v);
    }
    for(int i=1;i<=N;i++)
        res+=i*(i+1LL)/2;
    cout<<res<<endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    solve();
    return 0;
}