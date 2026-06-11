#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    ll N,M;
    cin >> N >> M;
    vector<ll> H(N+10);
    vector<ll> ma(N+10);
    FOR(i,1,N+1){
        cin >> H[i];
        ma[i] = 0;
    }
    ll ans = 0;
    REP(i,M){
        ll A,B;
        cin >> A >> B;
        ma[A] = max(ma[A],H[B]);
        ma[B] = max(ma[B],H[A]);
    }
    FOR(i,1,N+1) if(H[i] > ma[i]) ans++;
    cout << ans << endl;
    return 0;
}