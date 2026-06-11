#include<iostream>
using namespace std;
int main()
{
 int h,a,s=0;
 cin>>h>>a;
 while(1)
 {
     h=h-a;
     s++;
     if(h<=0)
     {
         break;
     }
 }
 cout<<s<<endl;
    return 0;


}
