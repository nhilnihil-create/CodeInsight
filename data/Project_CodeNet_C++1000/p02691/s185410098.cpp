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
int main(){
    cout << fixed << setprecision(10);
    map<ll,ll> m1,m2;
    int n;
    cin >> n;
    rep(i,n){
        ll a;
        cin >> a;
        m1[i+a]++;
        m2[i-a]++;
    }
    ll ans = 0;
    for(auto u : m1){
        ans += u.second*m2[u.first];
    }
    cout << ans << endl;
    return 0;
}