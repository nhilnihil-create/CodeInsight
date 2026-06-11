#include<iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include<map>	
#include<cstring>
#include<iomanip>
#include <string>
#include <vector>	
#include<unordered_map>
#include<unordered_set>
using namespace std;


typedef long long unsigned llu;
typedef long double ld;
#define ll long long
#define PI 3.14159265358979323846
#define For(i, a, b) for (int i = a, sz = (int)b; i < sz; i++)
#define rFor(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fill(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0)
const int mod = 1000000007;
const ll inf = 1000000000009;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) { return a*b/gcd(a,b);}

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdoutn

int main()
{
	IO;
	map<int,int>m;
	ll n{},k{},q{};
	cin>>n>>k>>q;
	For(i,1,q+1){int x{};cin>>x; m[x]++;}
	vector<int>p(n+1);
	For(i,1,n+1)p[i]=k;
	For(i,1,n+1)
	{
		if(m[i]>0)p[i]-=q-m[i];
		else if(!m[i])p[i]-=q;
	}
	For(i,1,n+1)
	{
		if(p[i]>0)cout<<"Yes\n";
		else cout<<"No\n";
	}
	//system("pause");	
	return 0;
}