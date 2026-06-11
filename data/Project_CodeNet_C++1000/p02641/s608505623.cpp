#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	//int a[5];
	int ans,x,n,i;
	cin>>x>>n;
	if(n==0)
	cout<<x<<endl;
	else
	{  
	int a[102]={0};
	for(i=0;i<n;i++)
	{
	cin>>ans;
	a[ans]=1;
    }
    
int f,b,fans;
	for(i=x;i<=101;i++)
	{
	   if(a[i]==0)
	   {
	   f=i;
	   break;  
     }
 }
	for(i=x;i>=0;i--)
	{
	   if(a[i]==0)
	   {
	   b=i;
	   break;  
     } 
 }
b=x-b;
f=f-x;
if((f<b&&(x+f<=101))||(x-b<0))
fans=x+f;
else
fans=x-b;
cout<<fans;
}
}
