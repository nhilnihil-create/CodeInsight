#include <bits/stdc++.h>
#include<string.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
	IOS;
	int n,m;
	cin>>n>>m;
	ll sum=0;
	for(int i=0,a;i<m;i++)	{
		cin>>a;
		sum+=a;
	}
	if(n-sum<0)
	cout<<-1;
	else cout<<n-sum;
	
	}