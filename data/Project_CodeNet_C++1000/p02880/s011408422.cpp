#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
  int n;
  cin>>n;
  for (int i = 1; i <=9; ++i)
   	{ 
   		 for (int j = 1; j <= 9; ++j)
   	{
   		if (i*j==n)
   		{
   			cout<<"Yes";
   			return 0;
   		}
   	}
  		
   	}	
  	cout<<"No";

   return 0;
}
