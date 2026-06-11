#include<bits/stdc++.h>
using namespace std;

long long N;
//      active, index
vector<pair<long long, long long> >vec;

//          left,  right
long long dp[2005][2005];

int main(){
	cin >> N;
	for(long long i = 0; i < N; i++) {
		long long a;
		cin >> a;
		vec.push_back(make_pair(a, i));
	}

	sort(vec.begin(), vec.end(), greater<pair<long long, long long> >());

	long long ans = 0;
	for(long long i = 0; i < vec.size(); i++) {
		long long active = vec[i].first;
		long long index = vec[i].second;

		long long curnum = i;
		for(long long left = 0; left <= curnum; left++) {
			long long right = curnum - left;
			//leftにつける場合
			dp[left+1][right] = max(dp[left+1][right], dp[left][right] + active * abs(index - left));
			ans = max(ans, dp[left+1][right]);
			//rightにつける場合
			dp[left][right+1] = max(dp[left][right+1], dp[left][right] + active * abs(index - (N-1-right)));
			ans = max(ans, dp[left][right+1]);
		}
	}
	cout << ans << endl;
}
