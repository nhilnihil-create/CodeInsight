#include<bits/stdc++.h>
using namespace std;
queue<long long>q;
int k;
int tot=0;
int main()
{
	cin>>k;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);
	q.push(9);
	while(!q.empty())
	{
		long long  x=q.front();
		q.pop();
		//cout<<x<<endl;
		tot++;
		if(tot==k)
		  {
		  	cout<<x<<endl;
		  	return 0;
		  }
	 if(x%10==0)
	   {
	   	   q.push(x*10);
	   	   q.push(x*10+1);
	   }
	else if(x%10==9)
	  {
	  	q.push(x*10+8);
	  	q.push(x*10+9);
	  }
	else 
	  {
	  	q.push(x*10+x%10-1);
	  	q.push(x*10+x%10);
	  	q.push(x*10+x%10+1);
	  }
	}
	
}