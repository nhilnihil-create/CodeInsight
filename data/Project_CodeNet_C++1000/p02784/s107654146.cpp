#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
int H,N,P,s=0;
cin>>H>>N;
for(int i=1;i<=N;i++)
{
	cin>>P;
	s=s+P;
}
if(s>=H)
{
	cout<<"Yes";
}
else
{
	cout<<"No";
}
return 0;
} 