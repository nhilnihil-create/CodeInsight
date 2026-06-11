#include<iostream>
using namespace std;
long long gcd(long long a, long long b){ 
    if (a == 0) 
       return b;
       return gcd(b%a,a);
}
  
int main()
{
    long long a,b,max;
    cin>>a>>b;
    max=(a*b)/gcd(a,b);
    
    cout<<max;
}