
#include <iostream>
#include <utility>

using namespace std;

int main(){
   int A,B,C;
   scanf("%d %d %d",&A,&B,&C);

   if(A-B>=C){
       cout<<0<<endl;
   }else if(A-B<C){
       cout<<C-(A-B)<<endl;
   }


}
