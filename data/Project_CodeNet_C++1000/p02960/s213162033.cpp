#include<bits/stdc++.h>
using namespace std;




  



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
  string nish;
  cin>>nish;
  int siz=nish.size();
  vector<vector<long long int >>dp(siz+1,vector<long long int >(13,0));
  dp[0][0]=1;
  for(int i=0;i<siz;i++)
  {

  	for(int j=0;j<10;j++)
  	{
  		int index=nish[i]-'0';
  		if(nish[i]=='?')
  		{
  			index=j;
  		}
  		for(int k=0;k<13;k++)
  		{
  			int number=(10*k+index)%13;
  			dp[i+1][number]+=dp[i][k];
  			dp[i+1][number]%=1000000007;
  		}
  		if(nish[i]!='?')break;
  	}
  }

  cout<<dp[siz][5]<<endl;
	return 0;
}