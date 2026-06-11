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
const ll INF = 1LL << 60;


int main(void){
    int a[3][3];
    REP(i,3) REP(j,3) cin >> a[i][j];
    int n;
    cin >> n;
    int b[n];
    REP(i,n) cin >> b[i];
    bool x[3][3];
    REP(i,3)REP(j,3)x[i][j]=false;
    REP(i,n){
        REP(j,3){
            REP(k,3){
                if(a[j][k]==b[i])
                    x[j][k]=true;
            }
        }
    }
    string ans="No";
    REP(i,3)
        if(x[i][0] && x[i][1] && x[i][2]){
            ans="Yes";
        }
            
    REP(i,3)
        if(x[0][i] && x[1][i] && x[2][i]){
            ans="Yes";
        }
    
    if(x[0][0] && x[1][1] && x[2][2])
        ans="Yes";

    if(x[0][2] && x[1][1] && x[2][0])
        ans="Yes";
    cout << ans;
    return 0;
}