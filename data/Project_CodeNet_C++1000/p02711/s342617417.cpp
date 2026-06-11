#include <iostream>
using namespace std;


int main () {

 int n;
 cin >> n;
 
 bool flag= false;
 int r;
 while(n>0)
 {
 	r=n%10;
 	n=n/10;
 	
 	if(r==7)
 	{
		 flag=true;
		 break;
	 }
 }

  if(flag)
  {
	  cout << "Yes";
  }
  else
  {
		cout << "No";
  }
 
	return 0;
}
