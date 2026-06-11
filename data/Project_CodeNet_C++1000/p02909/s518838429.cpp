#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  if(s.compare("Sunny")==0)
  {
    cout<<"Cloudy"<<endl;
  }
  else if(s.compare("Cloudy")==0)
  {
    cout<<"Rainy"<<endl;
  }
  if(s.compare("Rainy")==0)
  {
    cout<<"Sunny"<<endl;
  }
  return 0;
} 