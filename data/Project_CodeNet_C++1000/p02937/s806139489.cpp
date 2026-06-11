#include<iostream>
using namespace std;
string s,t;
int nxt[2<<17][26];
int nownxt[26];
main()
{
	cin>>s>>t;
	int N=s.size();
	s+=s;
	for(int i=0;i<26;i++)nownxt[i]=-1;
	for(int i=s.size();i--;)
	{
		for(int j=0;j<26;j++)nxt[i][j]=nownxt[j];
		nownxt[s[i]-'a']=i;
	}
	int p=-1;
	long ans=0;
	for(int i=0;i<t.size();i++)
	{
		int q=(p<0?nownxt:nxt[p])[t[i]-'a'];
		if(q<0)
		{
			cout<<-1<<endl;
			return 0;
		}
		ans+=q-p;
		p=q%N;
	}
	cout<<ans<<endl;
}
