#include<iostream>
using namespace std;
int main()
{
  int D,T,S;
  cin>>D>>T>>S;
   float time=(float) D/S;
  if(time<=T)
  cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}