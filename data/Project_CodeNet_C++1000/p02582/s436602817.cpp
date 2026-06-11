#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
  cin>>s;
  int n=s.size();
  int ans=0;
  for(int i=0;i<n;i++)
  {
  	if(s[i]=='R')
    {
      int cnt=1;
		for(int j=i+1;j<n;j++)
        {
        	if(s[j]=='R')
              cnt++;
            else
                break;
        }
      ans = max(ans,cnt);
    }
  }
  cout<<ans<<endl;
}
