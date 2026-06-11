#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    long long n,i,j=0,k=0;
    cin>>s;
    n=s.size();
    for(i=(((n-1)/2)+2)-1;i<=(n-1);i++)
     {
         if(s[j]==s[i])
         {
             k++;
         }
         j++;      
     }
     if(k==((n-1)/2))
     {
         cout<<"Yes"<<endl;
     }
     else
     {
         cout<<"No"<<endl;
     }
     return 0;
}