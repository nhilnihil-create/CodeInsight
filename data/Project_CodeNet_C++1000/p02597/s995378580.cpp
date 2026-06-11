#include<bits/stdc++.h>
using namespace std;
int n;
char a[2222222];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int l=-1,r=n;
	int ans=0;
	while(l<r){
		l++;
		while(a[l]!='W'&&l<n)
			l++;
		r--;
		while(a[r]!='R'&&r>=0)
			r--;
		ans++;
	}
	cout<<ans-1<<endl;
	return 0;
}