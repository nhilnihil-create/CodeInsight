#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll rec(ll n){
    ll ans = 0;
    n /= 2;
    while(n/5 != 0){
        ans += n/5;
        n /= 5;
    }
    return ans;
}
int main(){
    cout << fixed << setprecision(10);
    ll n;
    cin >> n;
    if(n%2 == 0)cout << rec(n) << endl;
    else cout << 0 << endl;
    return 0;
}