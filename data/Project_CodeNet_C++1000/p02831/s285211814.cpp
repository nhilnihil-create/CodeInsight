#include <iostream>  
using namespace std; 
class gfg 
{ 
 public : long long int gcd(long long int a,long long int b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
 } 
 long long int lcm(long long int a,long long  int b)  
 {  
    return (a*b)/gcd(a, b);  
 }  
} ; 
int main()  
{  
    gfg g; 
    long long int a , b ;
    cin>>a>>b;
    long long int res=0;
    res=g.lcm(a, b);  
    cout<<res;
    return 0;  
}  