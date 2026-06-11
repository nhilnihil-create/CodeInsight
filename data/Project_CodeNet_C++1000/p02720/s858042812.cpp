#include <bits/stdc++.h>
using namespace std;
queue<unsigned long long> q;
int k,sum,last;
int main() 
{
	cin>>k;
	k-=1;
	for(int i=1;i<=9;i++)
	q.push(i);
   while(k--)
   {
   	unsigned long long temp=q.front();
   	q.pop();
   	int m=temp%10;
   	if(m!=0)
   	  q.push(temp*10+m-1);
   	q.push(temp*10+m);
   	if(m!=9)
   	  q.push(temp*10+m+1);
   }
   cout<<q.front(); 
	return 0;
}