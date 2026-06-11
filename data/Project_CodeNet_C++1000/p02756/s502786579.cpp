#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	string s;
	cin>>s;
	deque<char> deq;
	for(char c : s)
	{
		deq.push_back(c);
	}
	int Q;
	cin>>Q;
	int reverse=0;
	rep(cnt,Q)
	{
		int t;
		cin>>t;
		if(t==1)
		{
			reverse++;
			reverse%=2;
		}
		else
		{
			int f;
			cin>>f;
			char c;
			cin>>c;
			f+=reverse;
			f%=2;
			if(f==1)
			{
				deq.push_front(c);
			}
			else
			{
				deq.push_back(c);
			}
		}
	}
	string ans="";
	while(!deq.empty())
	{
		if(reverse==0)
		{
			ans+=deq.front();
			deq.pop_front();
		}
		else
		{
			ans+=deq.back();
			deq.pop_back();
		}
	}
	cout<<ans<<endl;
	return 0;
}
