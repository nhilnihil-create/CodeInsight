#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long h,n;
	cin>>h>>n;
	vector<pair<long long,long long>> magic(n);

	for(long long i=0;i<n;i++){
			cin>>magic.at(i).first>>magic.at(i).second;
	}

	vector<long long> dp(h+20000,inf);
	dp.at(0)=0;
	long long ans=inf;

	for(long long i=0;i<h;i++){
		for(long long j=0;j<n;j++){
			dp[i+magic.at(j).first]=min(dp[i+magic.at(j).first],dp[i]+magic.at(j).second);
			if(i+magic.at(j).first>=h) ans=min(ans,dp[i+magic.at(j).first]);
		}
	}

	cout<<ans<<endl;

	return 0;
}
