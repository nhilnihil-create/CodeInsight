#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)
const int MOD = 1000000007;

int main(void){
    ll X,gold500,gold5,ans = 0;
    cin >> X;
    gold500 = X/500;
    gold5 = (X-gold500*500)/5;
    ans = gold500 * 1000 + gold5*5;
    cout << ans << endl;
    return 0;
}