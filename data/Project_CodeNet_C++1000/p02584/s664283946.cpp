#include<bits/stdc++.h>
using namespace std;

int  main()
{
long int n,k,d;
cin>>n>>k>>d;
n=abs(n);
long int straight=min(k,n/d);
k-=straight;
n-=straight*d;
if(k%2==0)
cout<<n;
else
cout<<d-n;
return 0;
}