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
    int n,m;
    cin >> n >> m;
    int s[m],c[m];
    REP(i,m) cin >> s[i] >> c[i];
    REP(x,1000){
        int keta=1;
        int nx=x/10;
        vector<int> d(1,x%10);
        while(nx){
            keta++;
            d.push_back(nx%10);
            nx/=10;
        }
        if(keta!=n) continue;
        bool ok=true;
        reverse(ALL(d));
        REP(i,m){
            if(d[s[i]-1]!=c[i])ok=false;
        }
        if(ok){
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}