#include<bits/stdc++.h>

using namespace std;


int main()
{


/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/

 const int INF = 1e9 + 5;
 const int maxm = 1e5;

  string s1;
  string s2;
  int cnt=0;

  cin>>s1>>s2;

  for(int i=0; i<3;i++)
  {
  	if(s1[i] == s2[i])
  	{
  		cnt++;
  	}
  }

  cout<<cnt;

}





