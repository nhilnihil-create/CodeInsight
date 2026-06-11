#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const LL mod=1000000007;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={1,0,-1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,-1,-1,1,1};


int main(){
    int n;cin >> n;
    LL ans = 0;
    for (LL i = 1; i <= n; i++) {
        ans += i * (i + 1) / 2;
    }
    for (int i = 0; i < n - 1; i++) {
        LL u,v;cin >> u >> v;
        if(u > v) swap(u, v);
        v--;
        ans -= u * (n - v);
    }
    cout << ans << endl;
    return 0;
}
