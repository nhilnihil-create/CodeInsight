#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define watch(x) cout << (#x) << " is " << (x) << endl

typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef pair< double,double> dd;
#define pb push_back
#define eb emplace_back
#define sz(a) (int)a.size()
#define all(c) c.begin(),c.end()
#define FOR(i,a,b) for(i=a; i<b; i++)
#define FORR(i,a,b) for(i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define mp make_pair

const int INF = 1000000007;
const long long INFLL = (ll)INF * (ll)INF;

void solve()
{
	int x,val;
	for(int i=0;i<5;i++)
	{
		cin>>x;
		if(x==0)
		val = i+1;
	}
	cout<<val;
}
int32_t main()
{
	IOS;
	//int t;
	//cin>>t;
	//for(int i=0;i<t;i++)
	{
		solve();
		cout<<endl;
	}
	return 0;
}
