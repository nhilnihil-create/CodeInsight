#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
signed main(void){
    int x,y; cin>>x>>y;
    int ans = 0;
    if(x == 1&&y == 1) ans += 400000;
    if(x == 1) ans += 300000;
    if(x == 2) ans += 200000;
    if(x == 3) ans += 100000;
    x = y;
    if(x == 1) ans += 300000;
    if(x == 2) ans += 200000;
    if(x == 3) ans += 100000;
    cout<<ans<<endl;
}
