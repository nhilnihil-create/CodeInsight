#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int n;
void inc(int &a){(a += n) %= n;}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    ll ans = 0;
    multiset<pair<ll, int> > ms;
    vector<ll> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) ms.insert({b[i], i});
    while(!ms.empty()){
    	auto itr = ms.end();
    	itr--;
    	if(itr->first == a[itr->second]){
    		ms.erase(itr);
    		continue;
    	}
    	if(itr->first < a[itr->second]){
    		cout << -1 << endl;
    		return 0;
    	}
    	int le = itr->second - 1, ri = itr->second + 1;
    	inc(le);
    	inc(ri);
        ll num = b[le] + b[ri];
    	ll m = (itr->first - a[itr->second]) / num;
    	if(m == 0){
    		cout << -1 << endl;
    		return 0;
    	}
    	ans += m;
    	m *= num;
    	m = itr->first - m;
    	num = itr->second;
    	b[num] = m;
    	ms.erase(itr);
    	if(m > a[num])ms.insert({m, num});
    }
    cout << ans << endl;
    return 0;
}
