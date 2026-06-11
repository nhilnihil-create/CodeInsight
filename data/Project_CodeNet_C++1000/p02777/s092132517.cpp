#include <iostream>
using namespace std;


int main () {

string s,t,u;
int a,b;

  cin >> s >> t >> a >> b >> u;
  
  if(u==s)
  {
	  a--;
  }
  else if(u==t)
  {
	  b--;
  }
  
  cout << a << " " << b;

	return 0;
}