// In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;

int cnt[N], cnt2[N], sum[N];
vector<int> nums;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=0,x;i<n;i++) {
		cin >> x;
		cnt[x]++;
	}
	for(int i=0;i<N;i++) if(cnt[i]) nums.push_back(cnt[i]);
	sort(nums.begin(), nums.end());
	for(auto x : nums) cnt2[x]++, sum[x]+=x;
	for(int i=N-2;i>=0;i--)cnt2[i]+=cnt2[i+1];
	for(int i=1;i<N;i++) sum[i]+=sum[i-1];
	vector<int> ans(n+1,0);
	for(int i=1;i<=n;i++) {
		int x = cnt2[i+1]+sum[i]/i;
		ans[x] = max(ans[x],i);
	}
	for(int i=n-1;i>=1;i--) ans[i]=max(ans[i], ans[i+1]);
	for(int i=1;i<=n;i++) cout << ans[i] << "\n";
	return 0;
}
