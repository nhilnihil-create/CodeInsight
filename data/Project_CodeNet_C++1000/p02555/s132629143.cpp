//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
ll n,k,ans;
ll dp[1000005];
int main(){
    cin>>n;
    dp[0]=1;
    for(int i=3;i<=n;i++){
		for(int j=3;i-j>=0;j++){
			dp[i]=(dp[i]+dp[i-j])%1000000007;
		}
	}
	cout<<dp[n];
	//system("pause");
    return 0;
}
