#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define Endl endl
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
int dp[114514];
set<int> ts[114514];
signed main(){
	int n,m;
	cin>>n>>m;
	string st;
	cin>>st;
	for(int i=0;i<=110000;i++){
		dp[i] = LINF;
	}
	dp[n] = 0;
	ts[0].insert(n);
	multiset<int> cand;
	cand.insert(0);
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if( st[i] == '1' ){
			cnt ++ ;
		}
		else{
			cnt = 0;
		}
		if( cnt >= m ){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int i=n-1;i>=0;i--){
		if( st[i] == '0' ){
			auto it = cand.begin();
			dp[i] = *it + 1;
			cand.insert( dp[i] );
			ts[dp[i]].insert(i);
		}
		if( i+m <= n ){
			auto it = cand.lower_bound(dp[i+m]);
			if( it != cand.end() )cand.erase(it);
		}
	}
	int pos = 0;
	if( dp[0] > n ){
		cout<<-1<<Endl;
		return 0;
	}
	vector<int> ans;
	for(int i=dp[0]-1;i>=0;i--){
		auto it = ts[i].lower_bound(pos);
		ans.pb(*it-pos);
		pos = *it;
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}