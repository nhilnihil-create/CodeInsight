#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int H,W;
	cin>>H>>W;
	vector<string> s(H);
	rep(i,H)
	{
		cin>>s[i];
	}
	vector<vector<int>> l(H,vector<int>(W+1));
	vector<vector<int>> r(H,vector<int>(W+1));
	vector<vector<int>> t(H+1,vector<int>(W));
	vector<vector<int>> b(H+1,vector<int>(W));
	rep(i,H)
	{
		l[i][0]=0;
		r[i][0]=0;
		rep(j,W)
		{
			if(s[i][j]=='#')
			{
				l[i][j+1]=0;
			}
			else
			{
				l[i][j+1]=l[i][j]+1;
			}

			if(s[i][W-1-j]=='#')
			{
				r[i][j+1]=0;
			}
			else
			{
				r[i][j+1]=r[i][j]+1;
			}
		}
	}	
	rep(j,W)
	{
		t[0][j]=0;
		b[0][j]=0;
		rep(i,H)
		{
			if(s[i][j]=='#')
			{
				t[i+1][j]=0;
			}
			else
			{
				t[i+1][j]=t[i][j]+1;
			}
			if(s[H-1-i][j]=='#')
			{
				b[i+1][j]=0;
			}
			else
			{
				b[i+1][j]=b[i][j]+1;
			}
		}
	}
	int ans=0;
	rep(i,H)
	{
		rep(j,W)
		{
			ans=max(ans,l[i][j+1]+r[i][W-j]+t[i+1][j]+b[H-i][j]-3);
		}
	}
	cout<<ans<<endl;
	return 0;
}
