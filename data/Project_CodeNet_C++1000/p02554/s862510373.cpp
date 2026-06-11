#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int modpow(int x, int n, int m) {
if (n == 0) return 1%m;
long long u = modpow(x,n/2,m);
u = (u*u)%m;
if (n%2 == 1) u = (u*x)%m;
return u;
}

  
int main()
{
 
    long long int n,a,b,c;
    cin>>n;
    int m=1000000007;
    if(n==1|| n==0)  cout<<"0"<<endl;
    if(n==2)  cout<<"2"<<endl;
   if(n>=3) {
 
        a= modpow(10, n, m);
        b= modpow(9, n ,m);
        c=modpow(8, n, m);
 
      cout<< (a %1000000007+c %1000000007-(2*b)%1000000007 +1000000007)%1000000007<<endl;
        }
    return 0;
}
