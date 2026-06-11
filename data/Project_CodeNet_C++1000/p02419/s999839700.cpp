#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main()
{
  string w;
  string t;
  int i;
  int count=0;
  
  cin >> w;
  
  for(i=0;w[i]!='\0';i++)
  {
    w[i]=static_cast<char>(toupper(w[i]));
  }
  
  while(cin >> t)
  {
    //cin >> t;
    if(t=="END_OF_TEXT")
      break;
      
    for(i=0;t[i]!='\0';i++)
    {
       t[i]=static_cast<char>(toupper(t[i]));
    }
    
    if(t==w)
    {
      count++;
    }
    
  }
  
  cout << count <<"\n";
}