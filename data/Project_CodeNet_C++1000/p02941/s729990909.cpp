#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define rep11(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define repm(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sperase(v,n) (v).erase(remove(all(v), n), (v).end())
#define vdelete(v) (v).erase(unique(all(v)), (v).end())
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1000000007
#define INF LONG_LONG_MAX

int n,a[200000],b[200000],ans;
bool f=true;
priority_queue<pair<int,int>> pq;

signed main() {
    cin >> n;
    rep(i,n) cin >> a[i];
    rep(i,n) {
        cin >> b[i];
        pq.push(mp(b[i],i));
    }
    while(pq.size()) {
        int i = pq.top().se;pq.pop();
        int tmp = b[(i+n-1)%n] + b[(i+1)%n],kr = (b[i]-a[i])/tmp;
        b[i] -= tmp*kr;
        if (a[i] != b[i] && (!kr || !tmp)) {f=false;break;}
        if (b[i] > a[i]) pq.push(mp(b[i],i));
        if (b[i] < a[i]) {f=false;break;}
        ans += kr;
    }
    rep(i,n) if (a[i] != b[i]) f=false;
    if (f) cout << ans << endl;
    else cout << -1 << endl;
}


