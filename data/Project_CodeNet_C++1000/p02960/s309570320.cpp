#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
#define ll long long 
#define mod 1000000007

string s;
int dp[100009][13];

int solve(int idx, int sum) {
	// cout<<idx<<" "<<sum<<endl;
	if(idx == s.length())
		return sum == 5;

	if(dp[idx][sum] != -1) 
		return dp[idx][sum];
	

	int sm = sum;
	int ans = 0;

	sum *= 10;
	if(s[idx] != '?') {
		sum += (s[idx] - '0');
		sum %= 13;
		ans += solve(idx + 1, sum);
		ans %= mod;
	} else {
		for(int i = 0; i <= 9; i++){
			int ssum = sum;
			ssum += i;
			ssum %= 13;
			ans += solve(idx + 1, ssum);
			ans %= mod;
		}
	}

	return dp[idx][sm] = ans%mod;
}


int main() {
	memset(dp, -1, sizeof(dp));
	cin>>s;
	cout<<solve(0, 0)<<endl;;

}
