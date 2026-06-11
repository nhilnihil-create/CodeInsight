#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    ll A,B,N;
    cin >> A >> B >> N;
    ll ans = min(N,B-1);
    ans = floor(ans * A / B) - A * floor(ans/B);
    cout << ans << endl;
    return 0;
}