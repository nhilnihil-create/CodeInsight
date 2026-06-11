#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,i,sum = 0,mn = 1e16,x = 0;
	cin>>n;vector<long long int> a(n + 1);
	for (i=0;i<n;i++){
		cin>>a[i];sum+=a[i];
	}
	for (i=0;i<n;i++){
		x+=a[i];mn=min(mn,abs(sum-2*x));
	}
	cout<<mn<<endl;
}