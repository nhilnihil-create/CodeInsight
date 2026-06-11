#include <iostream>
using namespace std;
int main()
{
   char alph='0';
   cin>>alph;
   if(alph>=97 && alph<=122)
    {
       alph=alph+1;
       cout<<alph;
    }


    return 0;
}