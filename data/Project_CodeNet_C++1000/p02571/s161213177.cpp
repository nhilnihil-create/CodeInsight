/*in the name of Allah the most beneficent the most merciful.*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 1e18
#define MIN -1e18
#define MOD 1000000007
//#define mod2 20071027
//#define MOD 998244353
// #define base 100001
//#define mod 1000074259
#define base2 31
#define memz(a) memset(a, 0, sizeof(a))
#define memn(a) memset(a, -1, sizeof(a))
#define in1(a) scanf("%lld", &a)
#define in2(a, b) scanf("%lld%lld", &a, &b)
#define TC(c) printf("Case %lld:\n", ++c)
#define out(x) cout << #x << " -> " << x << endl;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FILE   freopen("input.txt", "r", stdin);  freopen("out.txt", "w", stdout);
using namespace std;
const int N = 300010;
string s,t;
ll cnt, res=MAX;

int solve() {
	cin>>s>>t;
	ll sz=s.length(), s2=t.length();
	for(int i=0;i<=sz-s2;i++)
	{
		cnt=0;
		for(int j=0, k=i;j<s2;j++,k++){
			if(s[k]!=t[j]) cnt++;
		}
		res=min(res, cnt);
	}
	printf("%lld\n", res);
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	return solve();
}