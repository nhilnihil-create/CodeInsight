#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int n= a.size();
	reverse(a.begin(),a.end());
	vector<int> s(2019);
	s[0]++;
	int sum=0,ten=1;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		sum+=(a[i]-'0')*ten;
		sum%=2019;
		ans+=s[sum];
		s[sum]++;
		ten*=10;
		ten%=2019;
	}
	cout<<ans;
	return 0;
}
