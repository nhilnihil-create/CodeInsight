#include<bits/stdc++.h>
using namespace std;
unsigned long long k;//要求第k位的lunlun数 
unsigned long long q[5000001],f=1,e=0;
int main()
{
	cin>>k;
	for(int i=1;i<=9;i++)q[++e]=i;//进队列 
	for(long long i=1;i<=k+1;i++)
	{
		long long m=q[f]%10;
		if(m<0||m>9)break;
		if(m-1>=0)//末尾可以添加数字 
			q[++e]=10*q[f]+m-1;
		q[++e]=10*q[f]+m;
		if(m+1<=9)//末尾可以添加数字 
			q[++e]=10*q[f]+m+1;
		f++;
	}
	cout<<q[k]<<endl;
	return 0;
}