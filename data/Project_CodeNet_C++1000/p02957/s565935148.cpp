#include <iostream>
#include<cmath>
using namespace std;
int main()
{    long double a,b;
     long double avg;
  cin>>a>>b;
  avg=(a+b)/2;
  if(avg==floor(avg))
    cout<<(long)avg<<endl;

  else  cout<<"IMPOSSIBLE"<<endl;
    return 0;
}

