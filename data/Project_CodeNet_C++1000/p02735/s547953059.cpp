#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h,w;
  	cin>>h>>w;
	vector<string>grid(h);
  	for(int i=0;i<h;i++)
    {
      cin>>grid[i];
    }
  	vector<vector<int>>dp(h,vector<int>(w,INT_MAX));
  	dp[0][0]=(grid[0][0]=='#');
  	for(int row=0;row<h;row++)
    {
      for(int col=0;col<w;col++)
      {
        if(row==0&&col==0)
            continue;
        if(row!=0)
        {
            dp[row][col]=min(dp[row][col],dp[row-1][col]+(grid[row][col]=='#'&&grid[row-1][col]=='.'));
        }
        if(col!=0)
        {
            dp[row][col]=min(dp[row][col],dp[row][col-1]+(grid[row][col]=='#'&&grid[row][col-1]=='.'));
        }
          
      }
    }
    cout<<dp[h-1][w-1]<<endl;
}
