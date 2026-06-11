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
    double L;
    cin >> L;
    double ans;
    ans = L * L * L / 27;
    printf("%.8f",ans);
    //cout << pow(ans,3) << endl;
    return 0;
}