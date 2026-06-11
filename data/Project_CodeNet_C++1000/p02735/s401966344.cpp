#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
typedef long long int ll; 
typedef long double ld; 


int main()
{	
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    
  int h,w;
  cin>>h>>w;

  vector <string> vec(h);

  for(int i=0;i<h;i++)
  {
      cin>>vec[i];
  }

  vector < vector <int> > dp(h, vector <int>(w,1e9+5));

  dp[h-1][w-1] = 0;

  for(int i=h-1;i>=0;i--)
  {
      for(int j=w-1;j>=0;j--)
      {
          if(i==h-1 && j==w-1)
          {
              continue;
          }
          if(i!=h-1)
            dp[i][j] = min(dp[i][j],dp[i+1][j]+((vec[i][j]=='.')&&(vec[i+1][j]=='#')));
          if(j!=w-1)
            dp[i][j] = min(dp[i][j],dp[i][j+1]+((vec[i][j]=='.')&&(vec[i][j+1]=='#')));
          
      }
  }

  cout<<dp[0][0]+(vec[0][0]=='#')<<endl;


}

