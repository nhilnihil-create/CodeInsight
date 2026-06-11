#include<bits/stdc++.h>
using namespace std;
bool result(int x, int y, int z, int e){
	return ((x*x+z*z+y*y+x*y+y*z+z*x) <= e);
}
int main()
{
	int n, k;
	cin>>n>>k;
	long *arr = new long[n];
	for(int x = 0; x < n; x++)
		cin>>arr[x];

	sort(arr, arr+n);
	for(int x = 1; x < k; x++)
		arr[0]+=arr[x];

	cout<<arr[0]<<endl;

	return 0;
}
