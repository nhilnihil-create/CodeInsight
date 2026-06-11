#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	ll p[n+1],c[n+1];
	for(int i = 1; i <= n;++i){
		cin >> p[i];
	}
	for(int i = 1; i <= n;++i){
		cin >> c[i];
	}
	ll ans = -1e17;
	for(int i = 1; i <= n;++i){
		ll sum = 0;
		ll max_ending_here = 0;
		ll max_so_far = -1e17;
		int cnt = 0;
		for(int j = p[i]; j != i && cnt < k;j = p[j]){
			++cnt;
			sum += c[j];
			max_ending_here = max_ending_here + c[j];
			if(max_so_far < max_ending_here)
				max_so_far = max_ending_here;
		}
		ans = max(ans,max_so_far);
		if(cnt < k){
			++cnt;
			ll temp = k/cnt;
			ll rem = k%cnt;
			int j = p[i];
			ll tsum = 0;
			sum += c[i];
			if(rem == 0)
				ans = max(ans,sum * (temp-1LL) + max_so_far);
			while(rem > 0){
				ans = max(ans,temp * sum + tsum);
				tsum += c[j];
				j = p[j];
				--rem;
			}
			ans = max(ans,temp * sum + tsum);
		}
	}
	cout << ans << "\n";
}
