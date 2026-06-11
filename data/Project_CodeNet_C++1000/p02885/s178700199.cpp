#include<iostream>
using namespace std;
main()
{
   int A,B,y,z;
   cin>>A>>B;
   if(A>B)
   {
       if(B*2<A)
       {
           y=B*2;
       z=A-y;
       cout<<z<<endl;
       }
       else
        cout<<"0"<<endl;
   }
   else
    cout<<"0"<<endl;
}
