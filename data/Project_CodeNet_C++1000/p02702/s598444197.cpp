#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);  
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define int long long
const int mod = 2019;
void test_case(){
	string s; cin>>s;
	int n = s.size();
	int suf = 0;
	map<int,int>cnt;
	cnt[suf]++;
	int ans = 0;
	int power_of_ten = 1;
	for(int i=n-1;i>=0;i--){
		int digit = s[i] - '0';
		suf = (suf + digit * power_of_ten) % mod;
		
		power_of_ten = (power_of_ten * 10) % mod;
		
		ans += cnt[suf];
		cnt[suf]++;
	}
	cout<<ans<<endl;
}
		

signed main(){
	IOS;
	int t=1; //cin>>t;
	while(t--){
		test_case();
	}
}
