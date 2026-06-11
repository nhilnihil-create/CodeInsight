#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[101],b=1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]%2==0){
			if(a[i]%3!=0&&a[i]%5!=0)b=0;
		}
	}
	if(b)cout<<"APPROVED";
	else cout<<"DENIED";
}
