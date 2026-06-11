#include<bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define ff first
#define ss second
typedef long long ll;

const int mod =1e9+7;

ll dp[20];
ll new_dp[20];



int main(){
	string s;cin>>s;
	dp[0]=1;
	int inv=1;
	for(int i=0;i<11;i++)inv=(10*inv)%13;
	for(char c: s){
		memset(new_dp,0,sizeof(new_dp));
		if(c=='?'){
			for(int i=0;i<10;i++)for(int rem=0;rem<13;rem++){
				int see=(rem-i+13)%13;
				see*=inv;
				see%=13;
				new_dp[rem]+=dp[see];
				new_dp[rem]%=mod;
			}
			swap(dp,new_dp);
			continue;
		}
		int val=c-'0';
		for(int rem=0;rem<13;rem++){
			int see=(rem-val+13)%13;
			see*=inv;
			see%=13;
			new_dp[rem]+=dp[see];
			new_dp[rem]%=mod;
		}
		swap(dp,new_dp);
	}
	cout<<dp[5]<<endl;

	return 0;
}
