#include<iostream>
#include<string>
using namespace std;
int main()
{
  long int n,result=1;
  cin>>n;
  string color;
  cin>>color;
  for(long int i=1;i<color.length();i++)
  {
    if(color[i-1]!=color[i])
    {
      result+=1;
    }
  }
  cout<<result;
}