#include <iostream>
#include<string>
using namespace std;

int main()
{
  int n,counter = 0;
  cin>>n;
  string s;
  cin>>s;

  for(int i=0;i<n-2;i++)
  {
      if(s[i]==char('A') && s[i+1]==char('B') && s[i+2]==char('C'))
      {
          counter++;
      }
  }
  cout<<counter;

    return 0;
}
