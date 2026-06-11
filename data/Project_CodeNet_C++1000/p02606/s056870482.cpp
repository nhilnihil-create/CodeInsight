#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9+7;

void solve(){
	int l,r,d,ans=0;cin >> l >> r >> d;
	for(int i = l;i<=r;++i){
		if(i%d==0)
			ans++;
	//	cout << d << ' ' << i << '\n';
	}
	cout << ans << '\n';			
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int t=1;
//	int t;cin >> t;
	while(t--) solve();
}