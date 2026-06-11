#include<bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  long long sc=0;
  for(int i=1;i<n;i++)
  {
  	if(a[i-1]>a[i])
  	{
  		sc = sc+a[i-1]-a[i];
  		a[i] = a[i-1];
	  }
  }
  cout<<sc<<endl;
  return 0;
}