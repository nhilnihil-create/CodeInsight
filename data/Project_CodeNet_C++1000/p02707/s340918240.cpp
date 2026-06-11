#include<bits/stdc++.h>
using namespace std;
int n,a[200010],x[200010];
int main(){
	cin>>n;
	for (int i=0;i<n-1;i++) cin>>a[i];
	for (int i=0;i<n-1;i++) x[a[i]]++;
	for (int i=1;i<=n;i++) cout<<x[i]<<endl;
	return 0;
}