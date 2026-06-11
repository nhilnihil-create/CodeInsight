#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int x,i;
	cin>>x>>i;
	string ans="No";
  for(int j=0;j<=x;j++)
  {
    int k=j*2+(x-j)*4;
    if(k==i)
      ans="Yes";
  }
  cout<<ans;

}
