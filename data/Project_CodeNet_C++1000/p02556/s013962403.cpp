#include <bits/stdc++.h>
#define mod 1000000007
#define f first
#define s second
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> x(n),y(n);
	vector<int> sum(n),diff(n);
	for(int i=0;i<n;i++){
		cin >> x[i] >> y[i];
		sum[i] = x[i]+y[i];
		diff[i] = x[i] - y[i];
	}
	sort(sum.begin(),sum.end());
	sort(diff.begin(),diff.end());
	cout << max(sum[n-1]-sum[0],diff[n-1]-diff[0]) << endl;
}

int main(){

/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif*/
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//int t;cin >> t;while(t--){solve();}
	solve();
	return 0;
}