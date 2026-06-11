//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define fo(i,n) for(int i=0;i<(n);i++)
#define inp(a) int a;cin>>a;
#define inpa(a,n)vector<int> a(n);fo(i,n)cin>>a[i];
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
using namespace std;
#define int ll
// #define MAX 20
#define INF (int)1e18

template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.F<<','<< P.S<<')';}


signed main()
{
	fio
	inp(n)
	inpa(a,n)
	inpa(b,n)
	int ans=0;
	priority_queue<pair<int,int>> pq;
	fo(i,n)
	{
		if(a[i]!=b[i])
			pq.push({b[i],i});
	}
	while(pq.size())
	{
		int val=pq.top().F;
		int ind=pq.top().S;
		pq.pop();
		if(val<a[ind])
		{
			cout<<-1<<'\n';
			return 0;
		}
		int x=(val-a[ind])/(b[(ind-1+n)%n]+b[(ind+1)%n]);
		if(x==0)
		{
			cout<<-1<<'\n';
			return 0;
		}
		ans+=x;
		b[ind]-=x*((b[(ind-1+n)%n]+b[(ind+1)%n]));
		if(b[ind]!=a[ind])
			pq.push({b[ind],ind});
	}
	cout<<ans<<'\n';
	printclock;
}