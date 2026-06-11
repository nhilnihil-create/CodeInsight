#include"bits/stdc++.h"

using namespace std;

#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define nl "\n"
#define sp " "
#define int long long
#define PI 3.141592653589793
#define scanstr(s) cin>>ws; getline(cin,s);

void solve()
{
	int n,m;
	cin>>n>>m;
	int s[m],c[m];
	for(int i=0;i<m;i++)
	{
		cin>>s[i]>>c[i];
	}
	for(int i=0;i<1000;i++)
	{
		string t=to_string(i);
		if(t.size()==n)
		{
			bool ok=true;
			for(int j=0;j<m;j++)
			{
				if(t[s[j]-1]!= '0'+c[j]) ok=false;
			}
			if(ok)
			{
				cout<<i<<endl;
				return ;
			}
		}
	}
	cout<<-1<<endl;
	return ;
}

int32_t main()
{
	FastIO;
	solve();
	return 0;
}
