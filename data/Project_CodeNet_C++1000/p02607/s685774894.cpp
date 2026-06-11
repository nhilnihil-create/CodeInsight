#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int>v(n+1);int counter=0;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]&1 && i&1)
		{
			counter++;
		}
	}
	cout<<counter<<endl;
	return 0;
}