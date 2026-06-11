#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,c;
	cin>>n>>k>>c;
	string s;
	cin>>s;
	vector<int>arr;
	for(int i=0; i<n; i++)
	{
		if(s[i]=='o')
		 arr.push_back(i+1);
	}
	vector<int>pos1,pos2;
	pos1.push_back(arr[0]);
	int last=arr[0];
	int cnt=1;
	for(int i=1; i<arr.size(); i++)
	{
		if(arr[i]-last>c){
			cnt++;
			pos1.push_back(arr[i]);
			last=arr[i];
		}
	}
	if(cnt==k)
	{
		int cnt2=1;
		int last=arr[arr.size()-1];
		pos2.push_back(last);
		for(int i=arr.size()-2; i>=0; i--)
		{
			if(last-arr[i]>c)
			{
				pos2.push_back(arr[i]);
				last=arr[i];
			    cnt2++;	
			}
		}
	//	cout<<"cnt2 : "<<cnt2<<"\n";
		if(cnt2==cnt)
		{
			reverse(pos2.begin(),pos2.end());
			for(int i=0; i<cnt; i++)
			{
				if(pos1[i]==pos2[i])
				 cout<<pos1[i]<<"\n";
			}
		}
	}
	return 0;
}