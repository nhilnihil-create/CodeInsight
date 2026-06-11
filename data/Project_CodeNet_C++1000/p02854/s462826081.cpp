#include<bits/stdc++.h>
using namespace std;
long long arr[1000000];
int main()
{
	long long n,i,sum = 0,mn = 1e16,x = 0;
	cin>>n;
	for (i=0;i<n;i++){
		cin>>arr[i];sum+=arr[i];
	}
	for (i=0;i<n;i++){
		x+=arr[i];mn=min(mn,abs(sum-2*x));
	}
	cout<<mn<<endl;
}