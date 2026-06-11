#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x,long long int y) 
{ 
    long long int res = 1;     // Initialize result 
  // x=x;
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x); 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x);  // Change x to x^2 
    } 
    return res; 
}
long long int power(long long int x,long long int y,long long int m) 
{ 
    long long int res = 1;     // Initialize result 
   x=x%m;
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x)%m; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x)%m;  // Change x to x^2 
    } 
    return res; 
}

long long int gcd(long long int a, long long int b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
 } 
 long long int lcm(long long int a, long long int b)  
 { 
     long long int temp;
    
    return (a*b)/gcd(a, b);  
 }
 
int main() {
   
   long long int i,j;
 //long long int b[1000000];
 //set<long long int >s;
       long long int f=0,p=0,z,o=0;
       double pie=3.141592653589793238;
    long long int n,m,l=0,k,c,min1=10000000000000,max2=-100;
    cin>>n;
    if(n%2==0)
    {
    cout<<0.5000000000;}
  else
  {
    double ma=ceil((double)n/2)/n;
    printf("%.8f",ma);
  }
      
 return 0;
}