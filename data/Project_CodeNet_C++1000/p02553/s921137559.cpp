#include<bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
#define endl '\n'
#define for(i,s,n) for(int i=s;i<n;i++) 
#define vii vector<int>
signed main()
{
        fast;
	int t = 1,a,b,c,d;
	//cin>>t;
	while (t--)
	{
		cin >> a>>b>>c>>d;
        cout<<max({(a*c),(a*d),(b*c),(b*d)});
	}
}