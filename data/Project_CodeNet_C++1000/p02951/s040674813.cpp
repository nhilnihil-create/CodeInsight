#include<iostream>
using namespace std;
int main()
{
   int A,B,C;
   cin>>A>>B>>C;
  if(A>=0&&B>=0&&C!=0&&A>=B&&B<=20&&C<=20){
   if((B+C)>A){
       cout<<(B+C)-A;
   }
   if((B+C)<=A){
       cout<<0;
   }
   }
    return 0;
}