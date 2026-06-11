#include<iostream>
#include<cctype>
using namespace std;
int main()
{
   char c;
   cin>>c;
   isupper(c)?cout<<"A": cout<<"a";
   return 0;
}
