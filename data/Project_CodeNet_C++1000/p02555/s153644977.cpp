#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=1000000000+5;
const int N=2e5+5;
const ll oo=1e18+5;
const ll mod=1e9+7;

void add_self(int& a,int b){
	a+=b;
	if(a>=mod) a-=mod;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	vector<int> dp(n+5);
	dp[0]=1;
	for(int sum=3;sum<=n;++sum){
		for(int num=3;num<=sum;++num){
			if(sum-num>=0) add_self(dp[sum],dp[sum-num]);
		}
	}
	cout<<dp[n];
	return 0;
}
