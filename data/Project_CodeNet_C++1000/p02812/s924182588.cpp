
// Problem : B - Count ABC
// Contest : AtCoder - AtCoder Beginner Contest 150
// URL : https://atcoder.jp/contests/abc150/tasks/abc150_b
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
		int n,ans=0;
		cin>>n;
		int i;
		string s;
		cin>>s;
		repf(i,0,n-2)
		{
			if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C') ans++;
		}
		cout<<ans;
    }
    return 0;
} 
