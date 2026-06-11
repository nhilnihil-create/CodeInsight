#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i, a, b, m, x, y, c, mn=99999999, arr[1000000], brr[1000000];
	cin>>a>>b>>m;
	for(i=0;i<a;i++)cin>>arr[i];
	for(i=0;i<b;i++)cin>>brr[i];
	for(i=0;i<m;i++){
		cin>>x>>y>>c;
		mn = min(mn, arr[x-1]+brr[y-1]-c);
	}
	sort(arr, arr+a);
	sort(brr, brr+a);
	mn = min(mn, arr[0]+brr[0]);
	cout<<mn<<endl;
}