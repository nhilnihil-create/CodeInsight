#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,i,j,k,c=0,d;
	cin>>n;
	long long a[n];
	cin>>a[0];
	for(i=1;i<n;i++){
		cin>>a[i];
		d=a[i-1]-a[i];
		if(d>0){
			a[i]+=d;
			c+=d;
		}
	}
	cout<<c<<endl;
	return 0;
}
