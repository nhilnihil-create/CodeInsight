#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const int mod = 1e9+7;

#define pi pair<int,int>
#define pl pair<lld,lld>

#define dump(x) cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define SANKOU(n,a,b) cout << ((n) ? (#a) : (#b) ) << endl

#define mem0(x) memset(x,0,sizeof(x))
#define fillnum(x,n) fill(begin(x),end(x),n)
#define asort(x) sort(x.begin(),x.end())
#define dsort(x,t) sort(x.begin(),x.end(),greater<t>())
#define vuniq(x) x.erase(unique(x.begin(), x.end()), x.end())

#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

int main() {
    ll N,M;
    cin >> N >> M;
    priority_queue<ll> que;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        que.push(a);
    }
    for (int i = 0; i < M; i++) {
        ll t = que.top();
        que.pop();
        que.push(t/2);
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
}