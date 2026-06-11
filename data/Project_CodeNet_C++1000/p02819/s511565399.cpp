#include<bits/stdc++.h>

using namespace std;

bool prime(int x)
{
	if(x==2) return true;
	if(x<2 || x%2==0)
	return false;
	int root=sqrt(x);
	for(int i=3;i<=root;i+=2)
	{
		if(x%i==0)
		return false;
	}
	return true;
}
int main()
{
     int x;
     cin>>x;
     while(1)
     {
        bool res = prime(x);
     	if(res)
     	{
     		cout<<x;
     		return 0;
		}
		x++;
	 }   
}