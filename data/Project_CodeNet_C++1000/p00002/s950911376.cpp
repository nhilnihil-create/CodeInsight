#include <iostream>
using namespace std;

int main()
{
  int a,b;
  while(cin>>a>>b)
  {
	  a+=b;
	  int count = 0;
	  while(a!=0)
	  {
		  a /= 10;
		  count++;
	  }
	  cout<<count<<endl;
  } 
	return 0;
}