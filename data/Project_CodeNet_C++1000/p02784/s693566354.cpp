#include <iostream>
using namespace std;

int main()
{
  long int H, N , x , sum = 0 ;
   cin>>H>>N;
   for(int i = 1; i<=N;i++)
   {
       cin>>x;
       sum+=x;

   }
   if(H<=sum)
   {
       cout<<"Yes"<<endl;
   }
   else if(H>sum)
   {
       cout<<"No"<<endl;
   }


    return 0;
}