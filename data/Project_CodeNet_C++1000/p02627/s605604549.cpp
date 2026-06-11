#include<iostream>
using namespace std;
char Solve(char c)
{
  if(isupper(c))
  {
    return 'A';
  }
  else
  {
    return 'a';
  }
}
int main()
{
  char c;
  cin>>c;
  cout<<Solve(c)<<"\n";
    return 0;
}