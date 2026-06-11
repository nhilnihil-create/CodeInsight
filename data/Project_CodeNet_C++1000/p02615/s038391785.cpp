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
int main(){
    cout << fixed << setprecision(10);
    ll n;
    cin >> n;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    ll ans = 0;
    sort(v.rbegin(),v.rend());
    ans += v[0];
    int i = 0;
    int cnt = 2;
    n--;
    while(--n){
        if(cnt %2 == 0) i++;
        ans += v[i];
        cnt++;
    }
    cout << ans << endl;
    return 0;
}