#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	ll N;
	cin>>N;
	N--;
	vector<char> ans;
	while(N>=0)
	{
		ans.push_back((char)('a'+N%26));
		N/=26;
		N--;
	}
	reverse(ans.begin(),ans.end());
	rep(i,ans.size())
	{
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
