#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  int cnt=0,flg=0;
  string u[260]={},t[260]={};
  
  cin >> n;
  for(int i=0;i < n;i++)
    {
      cin >> u[i];
    }
  
  cin >> m;
  for(int j=0;j < m;j++)
    {
      cin >> t[j];
    }

  for(int j=0;j < m;j++)
    {
      flg=0;
      for(int i=0;i < n;i++)
	{
	  if(t[j]==u[i] && cnt ==0)
	    {
	      cnt++;
	      flg = 1;
	      cout << "Opened by " << t[j] << endl;
	    }
	  else if(t[j]==u[i] && cnt ==1)
	    {
	      cnt--;
	      flg = 1;
	      cout << "Closed by " << t[j] << endl;
	    }
	}
      if(flg==0)
	{
	  cout << "Unknown " << t[j] << endl;
	}
    }
}
