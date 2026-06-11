#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
          double a,b=0;
          cin>>a;
          for(int i=1;i<=a;i++)
          {
                    if(i%2==0)
                              b++;
          }
          cout<<fixed<<setprecision(10)<<1-(b/a)<<endl;
return 0;
}
