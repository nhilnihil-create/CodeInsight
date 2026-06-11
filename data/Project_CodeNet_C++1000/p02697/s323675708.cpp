#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    if(n & 1){
    	ll mid = n / 2;
    	for(int i=0;i<m;i++){
    		cout << mid - i << " " << mid + 1 + i << endl;
    	}
    }else{
    	if(n == 4){
    		cout << 1 << " " << 2 << endl;
    	}else{
    		vector<pair<ll, ll> > v;
    		ll k = n / 2;
    		ll mid = k / 2;
    		for(int i=0;mid - i >= 1 ;i++){
    			v.push_back({mid - i, mid + 1 + i});
    	    }
    	    k++;
    	    mid = ( n + k ) / 2;
    	    for(ll i = 1; mid + i <= n; i++){
    	    	v.push_back({mid - i, mid + i});
    	    }
    	    for(int i=0;i<m;i++){
    	    	cout << v[i].first << " " << v[i].second << endl;
    	    }
    	}
    }
    return 0;
}
