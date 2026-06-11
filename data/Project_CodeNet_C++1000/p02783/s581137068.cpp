#include <iostream>
using namespace std;



int main()
{
   int H , A,coun = 0;
   cin>>H>>A;

   for( int i =0; H>0;i++)
   {
       H = H - A;
       coun+=1;
   }
   cout<<coun;


    return 0;
}