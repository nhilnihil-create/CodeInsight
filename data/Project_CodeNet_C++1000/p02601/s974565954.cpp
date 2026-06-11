
// Problem : B - Magic 2
// Contest : AtCoder - M-SOLUTIONS Programming Contest 2020
// URL : https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sort(a) sort(all(a))
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define vll vector<ll>
#define pll pair<ll,ll>
#define mod (int)1e9+7
#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define repf(i,a,b) for(i=a;i<b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define N 100005
int main()
{
	FAST
    int t=1;
    // cin>>t;
    while(t--)
    {
		int a,b,c;
		int k;
		cin>>a>>b>>c>>k;
		if(c>b && b>a) cout<<"Yes";
		else
		{
			int cnt;
			if(!(b>a))
			{
				cnt=0;
				while(b<=a) b*=2,cnt++;
			}
			if(c<=b)
			{
				while(c<=b) c*=2,cnt++;
			}
			if(cnt<=k) cout<<"Yes";else cout<<"No";
		}
    }
    return 0;
} 
