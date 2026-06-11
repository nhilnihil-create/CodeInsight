/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
#define sd(x)     scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100005
#define maxn 	  200005
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


int main()
{	
	int n,d;
	cin >> n >> d;
	int grid[n][d];
	for (int i=0 ; i<n ; i++)
	{
		for (int j=0 ; j<d ; j++)
		{
			cin >> grid[i][j];
		}
	}
	int cnt = 0;
	for (int i=0 ; i<n ; i++)
	{
		for (int j=i+1 ; j<n ; j++)
		{
			double y=0;
			{
				for (int k=0 ; k<d ; k++)
				{
					double x = grid[i][k] - grid[j][k];
					y+=x*x;
				}
				y=sqrt(y);
				if(y-(int)y==0) cnt++;
			}
		}
	}
	cout << cnt << endl;
}