#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int>v;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	int sum=0;
	for(int i=0;i<k;i++){
		sum+=v.at(i);
	}
	cout<<sum<<"\n";

	
	
		


	
	return 0;
}