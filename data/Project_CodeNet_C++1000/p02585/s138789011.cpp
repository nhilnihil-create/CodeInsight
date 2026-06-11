#if __has_include("debug.h")
    #include "debug.h"
#else  
#include <bits/stdc++.h>
using namespace std;
#define d(...) 2;
#endif

#define int long long int
#define ld long double

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"      

#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define ff first
#define ss second
#define eps 1e-10
#define PI acos(-1LL)

#define gcd(a,b)            __gcd((a),(b))
#define lcm(a,b)            ((a*b)/gcd(a,b))

void solve();

vector<int>a,score;

vector<int>find_cycle(int i)
{
	int tmp=i,pf=0;
	vector<int>pref;
	while(a[tmp]!=i)
	{
		tmp=a[tmp];
		pf+=score[tmp];
		pref.push_back(pf);
	}
	tmp=a[tmp];
	pf+=score[tmp];
	pref.push_back(pf);
	return pref;
}

int32_t main()
{
    #ifdef DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif 

    fast
    
    int t = 1;
	// cin>>t;
	
	while(t--)
	    solve();
	return 0;  
}

void solve()
{
	int i,j;

	int n,k;
	cin>>n>>k;

	a.resize(n+1);
	score.resize(n+1);

	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	for(i=1;i<=n;i++)
	{
		cin>>score[i];
	}

	vector<vector<int>>v;

	for(i=1;i<=n;i++)
	{
		vector<int>pf=find_cycle(i);
		v.push_back(pf);
	}

	d(v);

	int Max=-1e18;

	for(int i=1;i<=n;i++)
	{
		int here=-1e18,j;
		if(k>v[i-1].size())
		{
			d(k);
			if(v[i-1].back()<=0)
			{
				for(j=0;j<v[i-1].size();j++)
				{
					here=max(here,v[i-1][j]);
				}
			}
			else
			{
				int num_of_cycles=k/v[i-1].size();
				d(num_of_cycles);
				here=num_of_cycles*v[i-1].back();
				int remain=k%v[i-1].size();
				d(remain);

				int new_add=(num_of_cycles==0?INT_MIN:0);

					for(int j=0;j<remain;j++)
					{
						new_add=max(new_add,v[i-1][j]);
					}
				here+=new_add;

				int new_here,nxt=0;

				if(num_of_cycles)
				{
					num_of_cycles--;
					new_here=num_of_cycles*v[i-1].back();
					for(j=0;j<v[i-1].size();j++)
					{
						nxt=max(nxt,v[i-1][j]);
					}
					new_here+=nxt;

				}

				here=max(here,new_here);
			}
		}
		else
		{
			for(j=0;j<k;j++)
			{
				here=max(here,v[i-1][j]);
			}
		}
		Max=max(Max,here);
	}
	cout<<Max<<endl;
	

}