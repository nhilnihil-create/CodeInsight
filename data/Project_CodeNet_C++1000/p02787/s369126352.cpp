#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

const int maxn = 1e5+10;

int dp[maxn];

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int h,n;
	cin>>h>>n;
	vi a(n),b(n);
	for(int i=0;i<n;++i){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<maxn;++i){
		dp[i]=112345678;
	}
	for(int i=0;i<=h;++i){
		for(int j=0;j<n;++j){
			if(i-a[j] <= 0) dp[i] = min(dp[i],b[j]);
			else dp[i] = min(dp[i],b[j]+dp[i-a[j]]);
		}
	}
	cout<<dp[h]<<endl;
	return 0;
}