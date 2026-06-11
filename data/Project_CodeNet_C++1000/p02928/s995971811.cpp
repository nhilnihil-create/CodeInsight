#include<bits/stdc++.h>
using namespace std;
int a[2005];
int main() {
	long long n,k;
	cin>> n >> k;
	for(int i=1; i<=n; ++i)
		cin >> a[i];
	long long sum=0;
	long long num=1e9+7;
	for(int i=1; i<=n; ++i) 
	{
		long long left=0,right=0;
		for(int j=1;j<i;++j)
		   if(a[j]<a[i]) ++left;
		for(int  j=i+1;j<=n;++j)
		   if(a[i] > a[j]) ++right;
		long long t=0;
		t=k*(k-1)/2;
		t%=num;
		t*=left;
		t%=num;
		sum+=t;
		sum%=num;
		t=k*(k+1)/2;
		t%=num;
		t*=right;
		t%=num;
		sum+=t;
		sum%=num;
	}
	cout<<sum<<endl;
    return 0;
}