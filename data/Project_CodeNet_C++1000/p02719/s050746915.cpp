#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
long long  n,k,s,p;
   cin>>n>>k;

s=n%k;
p=abs(s-k);
if(p>s)
{
printf("%lld\n",s);
}
else
{
printf("%lld\n",p);
}


}