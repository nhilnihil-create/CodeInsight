#include<iostream>
using namespace std;
int main()
{
    int sum=0,n,i;
    string str;
    cin>>n;
    cin>>str;
    for(i=0;i<n;i++)
   {

     if(str[i]=='A' && str[i+1]=='B' && str[i+2]=='C')
     {
         sum++;
     }

   }
   cout<<sum<<endl;
 return 0;
}
