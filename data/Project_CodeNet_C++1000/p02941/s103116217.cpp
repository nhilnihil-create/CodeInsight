#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e5+100;

int a[N], b[N];

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin >> n;
	set<ii> st;
	for(int i=0 ; i<n ; i++)
		cin >> a[i];
	for(int i=0 ; i<n ; i++){
		cin >> b[i];
		st.insert(ii(b[i], i));
	}
	ll ans=0;
	while(!st.empty()){
		ii v = *st.rbegin();
		st.erase(v);
		int cur = v.second;
		int nxt = (v.second+1)%n;
		int prv = (v.second-1+n)%n;
		if(b[cur] == a[cur])
			continue;
		int s = b[prv] + b[nxt];
		if(b[cur] < a[cur] || b[cur] < s){
			cout << "-1\n";
			return 0;
		}
		if(a[cur] < s){
			ans += b[cur]/s;
			b[cur] %= s;
			st.insert(ii(b[cur], cur));
			continue;
		}
		if(b[cur] - a[cur] < 0 || (b[cur] - a[cur]) % s != 0){
			cout << "-1\n";
			return 0;
		}
		ans += (b[cur] - a[cur]) / s;
		b[cur] = a[cur];
	}
	cout << ans << "\n";
 	return 0;
}














