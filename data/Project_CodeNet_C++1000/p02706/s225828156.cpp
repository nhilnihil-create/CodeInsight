
#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long
#define ld long double
#define pf push front
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define gcd(a,b) __gcd(a,b)
#define pq priority_queue<int,vector<int>,greater<int> >
#define pq1 priority_queue<pll,vector<pll>,greater<pll> >

const int mod = 1e9+7;



int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll sm = 0;
	ll d;
	for (int i = 0; i < m; ++i)
	{
		cin>>d;
		sm += d;
	}
	if(sm>n) cout<<-1;
	else cout<<n-sm;
	return 0;
}
