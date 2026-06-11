#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

struct SegmentTree {
private:
    ll n;
    vector<ll> node;

public:
    SegmentTree(vector<ll> v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(ll x, ll val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }

    ll getmin(ll a, ll b, ll k=0, ll l=0, ll r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];

        ll vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    string s;
    cin >> n >> m >> s;
    SegmentTree seg(vector<ll> (n+1, INF));
    seg.update(n, 0);
    for(ll i=n-1;i>=0;i--){
    	if(s[i] == '0')seg.update(i, seg.getmin(i+1, min(i+m+1, n+1)) + 1);
    }

    if(seg.getmin(0, 1) >= INF) cout << -1 << endl;
    else{
    	ll ma = seg.getmin(0, 1);
    	vector<ll> dp(ma+1, INF);

    	for(ll i=0;i<=n;i++){
    		ll num = seg.getmin(i,i+1);
    		if(num <= ma){
    			dp[num] = min(dp[num], i);
    		}
    	}
    	for(int i=ma;i>0;i--){
    		cout << dp[i-1] - dp[i] << " ";
    	}
    	cout << endl;
    }
    return 0;
}
