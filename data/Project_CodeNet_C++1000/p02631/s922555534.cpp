#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int n;
	cin>>n;
	cin>>a[1];
	int t=a[1];
	for(int i=2;i<=n;++i) 
	    cin>>a[i],t^=a[i];
	for(int i=1;i<=n;++i)
	    cout<<(t^a[i])<<" ";
	cout<<endl;
	return 0;
}