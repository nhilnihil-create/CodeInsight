#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> data,test;
	int i,j,n,count=0;
	cin >> n;
	
	for(i=0;i<n;i++)
	{
		cin >> j;
		data.push_back(j);
		test.push_back(j);
	}
	
	sort(data.begin(),data.end());
	
     for(i=0;i<n;i++)
	{
		if(data[i]!=test[i]) count++;
	}
	
	if(count == 2 || data == test) cout << "YES";
	else cout << "NO";
}