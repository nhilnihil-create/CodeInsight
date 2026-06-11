#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b, int c){
    int m;
    m=min(min(a,b), c);
    
    for(int i=m ; i>=1 ; i--)
    {
        if(a%i==0 && b%i==0 && c%i==0)
        return i;
    }
}

int main()
{int k, p, q, r;
 unsigned long long int sum=0;
 cin>>k;
 
 for(p=1 ; p<=k ; p++)
 {
     for(q=1 ; q<=k ; q++)
     {
         for(r=1 ; r<=k ; r++)
         sum+=GCD(p,q,r);
     }
 }
 
 cout<<sum;
 return 0;
}