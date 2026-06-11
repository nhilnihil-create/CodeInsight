#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main() {
long long int a,b,k,flag=0,i;
cin>>a>>b;
if(a<b){
for(i=a;i<=b;i++)
{
    if(abs(a-i)==abs(b-i))
   { k=i;
   flag=1;
    break;}
}
}
else
{
    for(i=b;i<=a;i++)
{
    if(abs(a-i)==abs(b-i))
   { k=i;
   flag=1;
    break;}
}
}
if(flag==1)
cout<<k;
else
cout<<"IMPOSSIBLE";
}