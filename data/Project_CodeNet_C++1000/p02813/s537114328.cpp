#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main(){
	fast;
	int n,val,ans=0;
	bool end=true;
	cin>>n;
	vector<int> v1,v2;
	string s1,s2;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		v1.push_back(val);
		s1+=val;
	}
	for(int i=0;i<n;i++)
	{
		cin>>val;
		v2.push_back(val);
		s2+=val;
	}
	while(1)
	{
		if(v1==v2)
		{
			cout<<ans;
			return 0;
		}
		if(s1<s2)
		next_permutation(v1.begin(),v1.end());
		else
		next_permutation(v2.begin(),v2.end());		
		ans++;
	}
	return 0;
}

