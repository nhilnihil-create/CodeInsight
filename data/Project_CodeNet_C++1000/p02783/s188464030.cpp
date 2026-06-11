#include<iostream>
using namespace std;
int main()
{
   int i,c=0,a,b,sub;
   cin>>a>>b;
   for(i=1; ;i++)
   {
       sub=a-b;
       a=sub;
       if(sub<=0)
       {
           break;
       }


   }

    cout<<i<<endl;

  return 0;
}
