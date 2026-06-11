#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
long long n;
cin>>n;
long long a[n],s=0;
for(int i=0;i<n;i++)
{
if((i+1)%3==0||(i+1)%5==0)
a[i]=0;
else
a[i]=i+1;
s=s+a[i];
}
cout<<s;
}
