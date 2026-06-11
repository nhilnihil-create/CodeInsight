#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
     long long a,b,c,d;
     cin>>a>>b>>c;
     if(a==b&&b==c)
     {
         cout<<"No"<<endl;
     }
     else if(a!=b&&a!=c&&b!=c)
     {
         cout<<"No"<<endl;
     }
     else
     {
         cout<<"Yes"<<endl;
     }
     return 0;
}