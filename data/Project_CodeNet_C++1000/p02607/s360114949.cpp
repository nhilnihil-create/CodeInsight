#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n; cin>>n;
	int arr[105];
	int total=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i+=2)
	{
		if(arr[i]%2!=0&&i%2!=0)
		{
			total++;
		}
	}
	cout<<total<<endl;
	return 0;
}
