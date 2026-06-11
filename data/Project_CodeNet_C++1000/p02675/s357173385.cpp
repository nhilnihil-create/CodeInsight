#include <iostream>
using namespace std;
int main()
{int n,r;
 cin>>n;
 r=n%10;
 if(r==2||r==4||r==5||r==7||r==9)
   cout<<"hon";
 else if(r==3)
   cout<<"bon";
   else
     cout<<"pon";
}
 