#include <iostream>
#include <string>
using namespace std;
int main()
{
  string t;
  string r;
  string s;
  cin >> t;
  int l=t.size()/2;
  for(int i = 0; i < l; i++){
    s+="hi";
  }
  if(s==t)
    r="Yes";
  else
    r="No";
  
  cout << r << endl;
  return 0;
}
