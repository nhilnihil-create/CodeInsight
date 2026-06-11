#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <numeric>
#include <queue>
#include <cstdio>
#include <cstring>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<n;++i)
#define mrep(i,n) for(ll i=n;i>=0;--i)
#define all(a) (a).begin(),(a).end()
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define pl pair<ll,ll>
#define inf 1001001001001001000
//#define mod 1000000007
#define mod 998244353
#define pi 3.1415926535
using namespace std;
struct __INIT {
	__INIT() {
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(15);
	}
}__init;

ll n,m,q;
vl a,b,c,d;

ll f(vl A,ll now){
    if(now == n){
        ll score = 0;
        rep(i,q){
            if(A[b[i]]-A[a[i]] == c[i]) score += d[i];
        }
        return score;
    }
    ll ret = 0;
    for(ll i = A[now-1];i<=m;i++) {
        A[now] = i;
        ret = max(ret,f(A,now+1));
    }
    return ret;
}

int main(void) {
    cin>>n>>m>>q;
    a = vl(q);
    b = vl(q);
    c = vl(q);
    d = vl(q);
    rep(i,q){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--,b[i]--;
    }
    ll ans = f(vl(n,1),1);
    cout<<ans<<endl;
	return 0;
}
