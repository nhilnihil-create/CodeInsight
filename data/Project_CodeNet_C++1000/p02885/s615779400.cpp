#include <bits/stdc++.h>
using namespace std;
void nil()
{
	int n,m;
	cin>>n>>m;
	if(m*2<n) 
	{
		cout<<n-(m*2)<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	
}
int main()
{
	#ifndef ONLINE_JUDGE

		freopen("input1.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif	
		nil();

}