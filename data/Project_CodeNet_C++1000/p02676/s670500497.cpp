#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin>>n;
  string s;
  cin>>s;
  if(s.size()<=n)
  {
  	cout<<s;
  }
  else{
  	for(int i=0;i<n;i++)
  	{
  		cout<<s[i];
	  }
	  cout<<"...";
  }
  return 0;
}