#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vec             vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define inf             1e18
#define no_of_test(x)        int x; cin>>x; while(x--)
const int mod = 1e9 + 7;
//actual code is at the top 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	no_of_test(x)
	{
      int n,r;
	  cin>>n>>r;
	  if(n>=10)
	  {
		  cout<<r<<'\n';
	  }	 
	  else
	  {
		  cout<<r+100*(10-n)<<'\n';
	  }
	  
	}
	return 0;
}
 