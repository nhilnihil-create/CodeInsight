#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N,M;
	cin>>N>>M;
	vector<int> wa(N,0);
	vector<bool> ac(N,false);
	rep(i,M)
	{
		int p;
		cin>>p;
		string s;
		cin>>s;
		p--;
		if(s=="AC")
		{
			ac[p]=true;
		}	
		else if(!ac[p])
		{
			wa[p]++;
		}
	}
	int ans_ac=0;
	int ans_wa=0;
	rep(i,N)
	{
		if(ac[i])
		{
			ans_ac++;
			ans_wa+=wa[i];
		}
	}
	cout<<ans_ac<<" "<<ans_wa<<endl;
	return 0;
}
