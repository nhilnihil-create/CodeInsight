#include <stdlib.h> 
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std; 

int main()
{
   string s;

   cin>>s;

   if(s.substr(2,1) == s.substr(3,1)) 
   {
       if(s.substr(4,1) == s.substr(5,1)) cout<<"Yes";
       else cout<<"No";
   }
   else cout<<"No";

    return 0;
}

