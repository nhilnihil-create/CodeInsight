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
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,x;cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n,vector<int>(m));
    REP(i,n){
        cin >> c[i];
        REP(j,m){
            cin >> a[i][j];
        }
    }
    int ans=inf;
    REP(t,1<<n){
        vector<int> b(m);
        int res=0;
        REP(i,n){
            if(t&(1<<i)){
                res+=c[i];
                REP(j,m){
                    b[j]+=a[i][j];
                }
            }
        }
        bool f=true;
        REP(i,m){
            if(b[i]<x) f=false;
        }
        if(f) chmin(ans,res);
    }
    cout << (ans==inf?-1:ans) << endl;
}