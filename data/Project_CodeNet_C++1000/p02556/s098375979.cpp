#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define F first
#define S second
#define f(i,s,n) for(int i=(int)s;i<=(int)n;++i)
#define Fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
void solve()
{
	int n;cin>>n;
	ll maxa=INT_MIN,mina=INT_MAX,maxb=INT_MIN,minb=INT_MAX;
	f(i,0,n-1){
		ll x,y;cin>>x>>y;
		ll a=x+y;
		ll b=x-y;
		maxa=max(maxa,a);
		mina=min(mina,a);
		maxb=max(maxb,b);
		minb=min(minb,b);
	}
	cout<<max(maxa-mina,maxb-minb)<<'\n';

}
int main()
{	Fast;
	//int t;cin>>t;
	//while(t--)
	solve();
}
/*
# TestCase
4
6 8
1 10
3 6
6 6

# Participant
7

# Expected
9
--------------
# TestCase
4
6 4
5 9
2 7
3 9

# Participant
7

# Expected
8
---------------
# TestCase
4
10 1
5 5
1 5
1 4

*/