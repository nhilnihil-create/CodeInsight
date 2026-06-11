#include<iostream>
#include <map>
using namespace std;
long long int gcd(long long int a,long long int b)
{
if(a==0)
return b;
if(b==0)
return a;
return gcd(b,a%b);
}
long long int lcm(long long int a,long long int b)
{
return (long long)a/gcd(a,b)*b;
}
int main()
{
int a,b;
cin>>a>>b;
cout<<(long long)lcm(a,b);
}
