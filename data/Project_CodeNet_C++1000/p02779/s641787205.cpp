#include <bits/stdc++.h>
#define pi 3.14159
#include <map>
#include <iterator>
using namespace std;
int main()
 {
 	long long int n,i,j,f=0;
 	cin>>n;
 	int a[n];
 	for(i=0;i<n;i++)
 		cin>>a[i];
 	map<int,int>arr;
 	map<int, int>::iterator itr;
 	for(i=0;i<n;i++)
 	{
 		arr[a[i]]++;
	 }
	 for( itr=arr.begin();itr!=arr.end();itr++)
	 	{
	 		if(itr->second>1)
	 			{
	 				f=1;
	 				break;
				 }
		 }
		if(f==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
 	
 }
