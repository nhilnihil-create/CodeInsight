
// Problem : A - Kyu in AtCoder
// Contest : AtCoder - M-SOLUTIONS Programming Contest 2020
// URL : https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_a
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
		int x;
		cin>>x;
		x/=100;
		if(x<6) cout<<8;
		else if(x<8) cout<<7;
		else if(x<10) cout<<6;
		else if(x<12) cout<<5;
		else if(x<14) cout<<4;
		else if(x<16) cout<<3;
		else if(x<18) cout<<2;
		else if(x<20) cout<<1;
    }
    return 0;
} 
