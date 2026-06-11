#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define dou  double 
#define endl "\n"

const int MOD=1e9+7;

void solve()
{
	int n,m,i,j,cnt,maxi=INT_MIN;
	string str1,str2;
	cin >> str1 >>str2;
	n = str1.size();
	m = str2.size();
	for(i=0;i<=n-m;i++)
	{
		cnt =0;
		for(j=0;j<m;j++)
		{
			if(str1[i+j] == str2[j])
				cnt++;
		}
		if(cnt>maxi)
			maxi = cnt;
	}
	cout << m-maxi << endl;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	solve();
}