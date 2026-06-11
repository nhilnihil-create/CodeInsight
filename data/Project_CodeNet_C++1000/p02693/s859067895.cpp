#include <bits/stdc++.h>
using namespace std;
int main()
{
  int i,p,K,A,B;
	1<=K<=1000;
	1<=A<=B<=1000;
	cin>>K;
	cin>>A>>B;
	for(i=A;i<=B;i++)
	{
		p=i%K;
	
	if(p==0)
	{
		cout<<"OK";
		break;
	}
	
}
   if(p!=0) 
   {
   	cout<<"NG";
   }
}