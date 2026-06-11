#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int a[100][2];
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=0;i<n-2;i++)
	{
		if(a[i][0]==a[i][1] && a[i+1][0]==a[i+1][1] && a[i+2][0]==a[i+2][1])
		{
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";




	
}