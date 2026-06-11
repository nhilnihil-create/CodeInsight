#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
long long a,b,k,x;
cin>>a;
cin>>b;
cin>>k;
x=a-k;
if(x<0&&k>a)
{
b=b+x;
x=0;
}
if(b<0)
{
b=0;
}
cout<<x<<" "<<b;
}

