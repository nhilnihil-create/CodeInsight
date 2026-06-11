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
    ll A,B,C,X,Y,ans = 0;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> re(A);
    vector<ll> bu(B);
    vector<ll> cl(C);
    REP(i,A) cin >> re[i];
    REP(i,B) cin >> bu[i];
    REP(i,C) cin >> cl[i];
    // 前処理
    sort(re.begin(), re.end(), greater<>());
    re.erase(re.begin()+X, re.end());
    sort(bu.begin(), bu.end(), greater<>());
    bu.erase(bu.begin()+Y, bu.end());
    sort(cl.begin(), cl.end(), greater<>());
    vector<ll> sum(X+Y+C);
    sum.insert(sum.begin(),re.begin(),re.end());
    sum.insert(sum.begin()+X,bu.begin(),bu.end());
    sum.insert(sum.begin()+X+Y,cl.begin(),cl.end());
    sort(sum.begin(),sum.end(),greater<>());
    ll i = 0;
    while(i < X+Y){
        ans += sum[i];
        i++;
    }
    cout << ans << endl;
    return 0;
}