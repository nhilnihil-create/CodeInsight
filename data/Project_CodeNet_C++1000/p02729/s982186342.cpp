#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)
#define INF 1e12
const int MOD = 1000000007;
typedef pair<ll,ll> P;

int main(void){
    int N,M,ans=0;
    cin >> N >> M;
    FOR(i,1,N) ans += i;
    FOR(i,1,M) ans += i;
    cout << ans << endl;
    return 0;
}