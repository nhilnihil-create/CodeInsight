#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define rep(i,a,b)  for (int i = a; i < b; ++i)
#define rrep(i,z,a) for (int i = z; i >= a; --i)
#define rep0(n)     for(int i = 0 ; i < n; ++i )
#define rep1(n)     for(int i = 1 ; i <= n; ++i )
#define pb          push_back
#define sd(x)       scanf("%d",&x)
#define tc          int test;cin>>test; while(test--)
#define all(v)      v.begin(),v.end()
#define ff          first
#define ss          second
#define mp          make_pair
#define IOS         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl        "\n"
#define spc         " "
#define mem0(a)     memset(a,0,sizeof(a))
#define extime      cout << endl << endl << "____"<<(float)clock() / CLOCKS_PER_SEC << "s____";
#define maxn        998244353
#define mod         1000000007
//#define ll          long long int
//typedef vector<ll>  vll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
void OJ()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int solve()
{
	string s;
	cin >> s;
	if (s == "RSS" || s == "SRS" || s == "SSR")cout << 1;
	else if (s == "SSS")cout << 0;
	else if (s == "RRR")cout << 3;
	else if(s=="RSR")cout<<1;
	else cout << 2;
	return 0;
}
signed main()
{
	OJ();
	IOS
	//tc
	solve();
	//extime
	return 0;
}