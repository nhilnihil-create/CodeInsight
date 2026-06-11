#include <iostream>
using namespace std;


int main ()
{

  string s1,s2;
  
  cin >> s1 >> s2;
  
  int count=0;
  
  if(s1[0]==s2[0])
  {
		count++;
  }
  if(s1[1]==s2[1])
  {
	  count++;
  }
  if(s1[2]==s2[2])
  {
	  count++;
  }
  
  cout << count << endl;

	return 0;
}









