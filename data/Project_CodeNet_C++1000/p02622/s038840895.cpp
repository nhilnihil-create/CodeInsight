#include <iostream>
#include <cstring>
using namespace std;

int main()
{
   int x=0 ; int z=0 ;
   char S[200001] , T[200001] ;
   cin>>S >>T ;
   for (int i=0 ; i< strlen(S) ; i++) {
    if (S[i]==T[i]) z++;
    else x++ ;

   }
   if (z==0&&x==0) cout<<z ;
   else cout<<x ;
    return 0;
}
