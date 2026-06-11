
// Problem : C - Count Order
// Contest : AtCoder - AtCoder Beginner Contest 150
// URL : https://atcoder.jp/contests/abc150/tasks/abc150_c
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
		int i,n;
		cin>>n;
		vi a(n);
		vi b(n),c(n);
		repf(i,0,n) cin>>b[i];
		repf(i,0,n) cin>>c[i];
		repf(i,0,n) a[i]=i+1;
		int ib,ic;
		int cnt=0;
		do {
			cnt++;
			if(b==a) ib=cnt;
			if(c==a) ic=cnt;
		}while (next_permutation(all(a)));
		cout<<abs(ib-ic);
    }
    return 0;
} 
