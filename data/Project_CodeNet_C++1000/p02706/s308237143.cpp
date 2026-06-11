#include<iostream>
using namespace std;
int main()
{
          long long int a,b,i,x=0,c;
          cin>>a>>b;
          while(b--)
          {
                    cin>>c;
                    x=x+c;
          }
          if((a-x) < 0)
                   cout<<"-1"<<endl;
          else
                    printf("%d\n",a-x);
          return 0;
}