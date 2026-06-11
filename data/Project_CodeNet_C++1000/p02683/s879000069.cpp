#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//const ll INF = 1LL << 60;
const int INF = 1001001001;



int main(void){
    int n,m,x;
    cin >> n >> m >> x;
    int c[n],a[n][m];
    REP(i,n){
        REP(j,m+1){
            if(j==0) cin >> c[i];
            else cin >> a[i][j-1];
        }
    }

    int ans=INF;

    for (int bit = 0; bit < (1<<n); ++bit) {
        int csum=0,asum[m]={0};
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) {
                csum+=c[i];
                REP(j,m) asum[j]+=a[i][j];
            }
        }
        bool flag=true;
        REP(j,m){
            if(asum[j]<x){
                flag=false;
                break;
            }
        }
        if(flag) chmin(ans,csum);
    }
    if(ans==INF) cout << -1;
    else cout << ans;
    return 0;
}