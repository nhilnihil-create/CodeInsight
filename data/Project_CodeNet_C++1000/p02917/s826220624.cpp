#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	long long sum=0;
	cin>>n;
	int a[n],b[n];
	cin>>a[1];
	b[0]=a[1];
	for(int i=2;i<n;i++){
		cin>>a[i];
		if(a[i]>=a[i-1]){
			b[i-1]=a[i-1];
		}
		else{
			b[i-1]=a[i];
		}
	}
	b[n-1]=a[n-1];
	for(int i=0;i<n;i++){
		sum+=b[i];
	}
	cout<<sum;
}
