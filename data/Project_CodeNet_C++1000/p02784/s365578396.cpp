#include<bits/stdc++.h>
using namespace std;
int main()
{

		int h,n;
		cin>>h>>n;
		int a[n],sum=0;
		for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum>=h)
	cout<<"Yes";
	else
	cout<<"No";
}