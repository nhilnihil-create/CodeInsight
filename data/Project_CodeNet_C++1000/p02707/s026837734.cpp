#include <bits/stdc++.h>
#include<string.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
	IOS;
	int n;
	cin>>n;
	vector<int> v(n+1);
	for(int i=1,a;i<n;i++)
	{
		cin>>a;
		v[a]++;
	}
	for(int i=1;i<=n;i++)
	cout<<v[i]<<endl;
	}