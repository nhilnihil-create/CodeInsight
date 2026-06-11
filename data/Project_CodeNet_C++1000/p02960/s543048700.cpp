#include<bits/stdc++.h>
using namespace std;
long long int dp[100005][13];
string a;

long long int get(int pos , int &n, long long int rem)
{
//	cout<<"Hari";
	if(pos>=n) {
		
		if(rem==5) return 1;
		
		return 0;
	}
	
	if(dp[pos][rem] != -1) return dp[pos][rem];
	if(a[pos]!='?') return dp[pos][rem]=get(pos+1,n,(10*rem+(a[pos]-'0'))%13)%1000000007;
	
	long long int res = 0;	
	
	for(int i=0;i<=9;++i)
	{
		res=(res+get(pos+1,n,(10*rem+i)%13))%1000000007;
//		cout<<rem<<"\n"<<" i = "<<i<<"\n";
	}
	
	return dp[pos][rem] = res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a;
	long long int L;
	memset(dp , -1 , sizeof dp);
	int n=a.size();
	L = get(0 ,n, 0);
	cout<<L<<"\n";
}
