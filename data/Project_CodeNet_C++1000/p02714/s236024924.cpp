#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	long long sum=0;
	string s;
	cin>>N>>s;
	vector<vector<int> >dp1(N,vector<int>(3)),dp2(N,vector<int>(3));
	vector<int>dp3(N);
	for(int i=0;i<N;i++)
		if(s[i]=='R')
			if(i>0) {
				dp1[i][0]=dp1[i-1][0]+1;
				dp1[i][1]=dp1[i-1][1];
				dp1[i][2]=dp1[i-1][2];
				dp2[i][0]=dp1[i-1][1];
				dp2[i][2]=dp1[i-1][2];
				for(int j=i-1;j>0;j--) dp3[i]+=dp2[j][1]-(2*j-i>=0&&(s[j]=='B'&&s[2*j-i]=='G'||s[j]=='G'&&s[2*j-i]=='B'));
			}
			else dp1[0][0]=1;
		else if(s[i]=='G')
			if(i>0) {
				dp1[i][0]=dp1[i-1][0];
				dp1[i][1]=dp1[i-1][1]+1;
				dp1[i][2]=dp1[i-1][2];
				dp2[i][0]=dp1[i-1][0];
				dp2[i][1]=dp1[i-1][2];
				for(int j=i-1;j>0;j--) dp3[i]+=dp2[j][2]-(2*j-i>=0&&(s[j]=='B'&&s[2*j-i]=='R'||s[j]=='R'&&s[2*j-i]=='B'));
			}
			else dp1[0][1]=1;
		else
			if(i>0) {
				dp1[i][0]=dp1[i-1][0];
				dp1[i][1]=dp1[i-1][1];
				dp1[i][2]=dp1[i-1][2]+1;
				dp2[i][1]=dp1[i-1][1];
				dp2[i][2]=dp1[i-1][0];
				for(int j=i-1;j>0;j--) dp3[i]+=dp2[j][0]-(2*j-i>=0&&(s[j]=='G'&&s[2*j-i]=='R'||s[j]=='R'&&s[2*j-i]=='G'));
			}
			else dp1[0][2]=1;
	for(int i=0;i<N;i++) sum+=dp3[i];
	cout<<sum<<"\n";
	return 0;
}
