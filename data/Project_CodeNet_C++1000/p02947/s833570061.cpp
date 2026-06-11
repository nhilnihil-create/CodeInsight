#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
int main()
{
	long long int i,n,p=0,j;
	map<string,long long int>cnt;
	map<string, long long int>::iterator itr;
	cin>>n;
	//string s[n];
//	for(i=0;i<n;i++)
//		cin>>s[i];
	for(i=0;i<n;i++)
		{
			int sum=0;
			string s;
			cin>>s;
			sort(s.begin(), s.end());
		//	for(j=0;j<10;j++)
		//		sum+=s[j]-'a';
			cnt[s]++;	
		}
		for(itr=cnt.begin();itr!=cnt.end();itr++)
			{
				p+=itr->second*(itr->second-1)/2;
			}
	cout<<p<<endl;
}