#include <iostream>
#include <string> 
using namespace std;
int main()
{
  string s;
  getline(cin,s);
  for(int i=0;i<3;i++)
  {
    cout<<s[i];
  }
}
