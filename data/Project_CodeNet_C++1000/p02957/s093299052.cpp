#include "iostream"
using namespace std;
int main()
{
long long int a,b;
cin>>a>>b;
//if((a%2==0 && b%2==0) || (a%2!=0 && b%2!=0))
if(a+b==(a+b)/2*2)
cout<<(a+b)/2;
else 
cout<<"IMPOSSIBLE";
}