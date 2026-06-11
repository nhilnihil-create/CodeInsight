#include<iostream>
#include<vector>
using namespace std;
string s;
long K;
main()
{
	cin>>s>>K;
	vector<pair<char,int> >A;
	A.push_back(make_pair(s[0],1));
	for(int i=1;i<s.size();i++)
	{
		if(A.back().first==s[i])A.back().second+=1;
		else A.push_back(make_pair(s[i],1));
	}
	if(A.size()==1)
	{
		long T=K*A[0].second;
		cout<<T/2<<endl;
		return 0;
	}
	long ans=0,T=0;
	ans+=A[0].second/2;
	for(int i=1;i+1<A.size();i++)T+=A[i].second/2;
	ans+=T*K;
	ans+=A.back().second/2;
	if(A[0].first==A.back().first)
	{
		ans+=(K-1)*((A[0].second+A.back().second)/2);
	}
	else
	{
		ans+=(K-1)*(A[0].second/2+A.back().second/2);
	}
	cout<<ans<<endl;
}
