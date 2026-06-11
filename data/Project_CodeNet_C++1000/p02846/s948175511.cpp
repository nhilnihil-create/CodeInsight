#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORR(i, m, n) for (int i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=998244353;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t1,t2,a1,a2,b1,b2;cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll u=a1-b1,v=a2-b2;
    if(u<0){
        u=-u,v=-v;
    }
    ll p=u*t1,q=u*t1+v*t2;
    if(q==0){
        cout << "infinity" << endl;
        return 0;
    }
    if(q>0){
        cout << 0 << endl;
        return 0;
    }
    cout << abs(p)/abs(q)*2+(abs(p)%abs(q)==0?0:1) << endl;
}