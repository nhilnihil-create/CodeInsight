
// Problem : B - Tag
// Contest : AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2020
// URL : https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//mst,pq,mp,st,q
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define all(x) begin(x),end(x)

int mod = 1e9+7;
int inf = 4e18;
const int N = 5e5+5;
		
signed main()
{
    io
    int tt = 1;
    //cin>>tt;
    while(tt--)
    {
		int a,b,c,d,t;
		cin>>a>>b>>c>>d>>t;
		if(a<=c)
		{
			int x = a+b*t;
			int y = c+d*t;
			if(x>=y)
			{
				cout<<"YES";
			}
			else
			{
				cout<<"NO";
			}
		}
		else
		{
			int x = a-b*t;
			int y = c-d*t;
			if(x<=y)
			{
				cout<<"YES";
			}
			else
			{
				cout<<"NO";
			}
		}		
    }
    return 0;
}
