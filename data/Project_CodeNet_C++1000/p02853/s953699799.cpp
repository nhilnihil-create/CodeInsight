#include<bits/stdc++.h>
using namespace std;
int sum[12834];
int main()
{
int a,b;
cin>>a>>b;
sum[1]=300000;
sum[2]=200000;
sum[3]=100000;
if(a>=4&&b>=4)
cout<<0;
else if(a==1&&b==1)
cout<<1000000;
else
cout<<sum[a]+sum[b];
}
