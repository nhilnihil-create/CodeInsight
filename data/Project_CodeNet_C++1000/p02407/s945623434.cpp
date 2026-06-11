#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	reverse(a,a+n);
	for(int i=0;i<n-1;i++)cout<<a[i]<<' ';
	cout<<a[n-1]<<"\n";
	return 0;
}
