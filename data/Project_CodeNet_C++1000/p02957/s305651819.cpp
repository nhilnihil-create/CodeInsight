#include<iostream>
using namespace std;
int main()
{
  long A,B,K;
  cin>>A>>B;
  if((A+B)%2==0)
  {
   K=(A+B)/2;
   cout<<K;
  }
  else
  {
    cout<<"IMPOSSIBLE";
  }

}
