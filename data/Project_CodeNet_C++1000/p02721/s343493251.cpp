#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,c;
	string s;
	cin>>n>>k>>c;
	cin>>s;
	vector<int> v1,v2;
	int last=-1e9,kk=k;
	for(int i=0;i<s.size();i++)
	{
		
		if(s[i]=='o'&&i>last+c){
			v1.push_back(i);
			kk--;
			last=i;
		}
		if(kk==0)break;
	}
	int up=-1e9;
	kk=k;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='o'&&i>up+c){
			v2.push_back(s.size()-i-1);
			kk--;
			up=i;
		}
		if(kk==0)break;
	}
	reverse(v2.begin(),v2.end());
	for(int i=0;i<k;i++)
	{
		if(v1[i]==v2[i])cout<<v1[i]+1<<endl;
	}
	return 0;
}