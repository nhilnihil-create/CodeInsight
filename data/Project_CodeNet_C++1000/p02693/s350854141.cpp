#include <iostream>
using namespace std;


int main () {
	
  int k,a,b;
  cin >> k;
  cin >> a;
  cin >> b;
  bool flag= false;
  
  for(int i=a; i<=b;i++)
  {
	  if(i%k==0)
	  {

		  flag = true;
		  break;
	  }

  }
  
  if(flag)
  {
		cout << "OK";
  }
  else
  {
		cout << "NG";
  }
	
	return 0;
}
