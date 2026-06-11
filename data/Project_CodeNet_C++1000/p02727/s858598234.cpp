#include<bits/stdc++.h>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int x,y,a,b,c;
	
	cin>>x>>y>>a>>b>>c;
	
	deque<int>arr;
	deque<int>arr2;
	deque<int>arr3;
	
	int num;
	
	for(int i=0;i<a;i++)
	{
		cin>>num;
		arr.push_back(num);
	}
	
	for(int i=0;i<b;i++)
	{
		cin>>num;
		arr2.push_back(num);		
	}	
	
	for(int i=0;i<c;i++)
	{
		cin>>num;
		arr3.push_back(num);		
	}		
	
	sort(arr.begin(),arr.end());
	sort(arr2.begin(),arr2.end());
	sort(arr3.begin(),arr3.end());
	
	reverse(arr3.begin(),arr3.end());
	
	while(arr.size()>x){ arr.pop_front();}
	while(arr2.size()>y){ arr2.pop_front();}
	
	while(arr3.size())
	{
		int variable=arr3.front();
		int minimo=min(arr.front(),arr2.front());
		
		if(variable<=minimo) break;
		
		if(arr.front()<arr2.front()){
			arr.pop_front();
			arr.push_back(variable);
		}
		else
		{
			arr2.pop_front();
			arr2.push_back(variable);
		}
		arr3.pop_front();
	}
	
	long long resultado=0;
	
	for(int i=0;i<arr.size();i++)
		resultado+=arr[i];
	
	for(int i=0;i<arr2.size();i++)
		resultado+=arr2[i];	
	
	cout<<resultado;
	
	return 0;
}
