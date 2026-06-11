#include<bits/stdc++.h>
using namespace std;

#define pi 3.141592653589
#define MOD 1000000007
#define to() int t; cin>>t; while(t--)
#define pb push_back
#define in insert
#define mp make_pair
#define ff first
#define ss second
#define si(s) s.size()
#define fori(it,v) for(it=v.begin();it!=v.end(); it++)
#define for1(low,high,k) for(int i=low;i<high;i+=k)
#define for11(low,high,k) for(int j=low;j<high;j+=k)
#define for2(low,high,k) for(int i=low;i<=high;i+=k)
#define rev(high,low,k)  for(int i=high;i>=low ;i-=k)
#define all(x) x.begin(), x.end()
#define fil(x,i) memset(x,i,sizeof(x));
#define setbits(x) __builtin_popcount(x)
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

void i_o() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
}

int main()
{
	boost; i_o();
	string s; cin >> s;
	int n = s.size();
	if (s[n - 1] == 's') s += "es";
	else s += "s";
	cout << s << endl;
	return 0;
}
