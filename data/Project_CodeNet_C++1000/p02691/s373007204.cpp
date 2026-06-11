#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    ll N,A;
    cin >> N;
    map<ll,ll> m,l;
    ll ans = 0;
    REP(i,N){
        cin >> A;
        ans +=m[i - A];
        m[A + i]++;
    }
    cout << ans << endl;
    return 0;
}