#include <iostream>

using namespace std;

int main()
{
    int cnt=0;
   for(int i=1;i<=5;i++)
   {
       int a;
       cin>>a;
       if(a==0) {cnt=i;}


   }
   cout<<cnt<<endl;
    return 0;
}
