#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <iomanip>
using namespace std;
int main(){
	int n,m;
	string s;
	cin>>n>>m>>s;
	long long dp[100001];
	int mae[100001];
	fill(dp,dp+n+1,1e9+7);
	dp[0]=0;
	for(int i=1;i<=m;i++){
		if(s[i]=='0'){
			dp[i]=1;
			mae[i]=0;
		}
	}
	for(int i=m+1;i<=n;i++){
		if(s[i]=='1'){
			continue;
		}
		bool f=1;
		for(int j=i-m;j<i;j++){
			if(s[j]=='0'){
				dp[i]=dp[j]+1;
				mae[i]=j;
				f=0;
				break;
			}
		}
		if(f){
			cout<<-1<<endl;
			return 0;
		}
	}
	int now=n;
	vector<int> ans;
	ans.push_back(now);
	ans.push_back(mae[now]);
	while(mae[now]){
		now=mae[now];
		ans.push_back(mae[now]);
	}
	reverse(ans.begin(),ans.end());
	vector<int> sna;
	for(int i=1;i<ans.size();i++){
		sna.push_back(abs(ans[i]-ans[i-1]));
	}
	for(int i=0;i<sna.size();i++){
		cout<<sna[i];
		if(i==sna.size()-1){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
	return 0;
}
