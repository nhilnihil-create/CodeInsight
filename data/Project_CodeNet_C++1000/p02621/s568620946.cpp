#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,sum;
    cin>>a;
    if(a>=1||a<=10)
      {
          sum=a+pow(a,2)+pow(a,3);
          cout<<sum;
      }
    return 0 ;
}

