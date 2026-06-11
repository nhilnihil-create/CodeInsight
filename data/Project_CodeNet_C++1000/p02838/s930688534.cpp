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
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    ll sum = 0;
    rep(i, 60){
        ll cnt = 0;
        rep(j,n){
            if((v[j]>>i) & 1) cnt++;
        }
        ll now = cnt * (n - cnt);
        now %= mod;
        rep(j,i){
            now *= 2;
            now %= mod;
        }
        sum += now;
        sum %= mod;
    }
    cout << sum << endl;
    return 0;
}