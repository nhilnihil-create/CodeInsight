#include <iostream>
#include <string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  if (s[s.size()-1]=='3')
  {
    cout<<"bon";
  }
  else if(s[s.size()-1]=='1' || s[s.size()-1]=='6' || s[s.size()-1]=='8' || s[s.size()-1]=='0')
  {
    cout<<"pon";
  }
  else{
    cout<<"hon";
  }
                                                                                                                                                                                                                                      
                                                                         
  
  return 0;
}