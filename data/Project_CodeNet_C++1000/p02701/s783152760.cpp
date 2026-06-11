#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    ll N;
    cin >> N;
    vector<string> S(N);
    REP(i,N) cin >> S[i];
    ll ans = 1;
    sort(S.begin(),S.end());
    FOR(i,1,N){
        if(S[i-1] == S[i]) continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}