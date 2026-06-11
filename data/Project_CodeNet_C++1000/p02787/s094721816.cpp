#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const int mod = 1e9+7;

#define pi pair<int,int>
#define pl pair<ll,ll>

#define dump(x) cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define SANKOU(n,a,b) cout << ((n) ? (#a) : (#b) ) << endl

#define mem0(x) memset(x,0,sizeof(x))
#define fillnum(x,n) fill(begin(x),end(x),n)
#define asort(x) sort(x.begin(),x.end())
#define dsort(x,t) sort(x.begin(),x.end(),greater<t>())
#define vuniq(x) x.erase(unique(x.begin(), x.end()), x.end())

#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)

int main() {
    ll H,N;
    vector<pl> S;
    ll dp[20010];
    fillnum(dp,LINF);
    cin >> H >> N;
    for (int i = 0; i < N; i++) {
        ll A,B;
        cin >> A >> B;
        S.pb(mp(A,B));
    }
    dp[0] = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            dp[i+S[j].first] = min(dp[i+S[j].first],dp[i]+S[j].second);
        }
    }
    ll ans = LINF;
    for (int i = H; i < H+10000; i++) {
        ans = min(ans,dp[i]);
    }
    cout << ans << endl;
}