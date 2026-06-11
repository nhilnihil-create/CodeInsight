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

int a[3][3];
int main()
{
	IO;
	For(i,0,3)
	{
		For(j,0,3)cin>>a[i][j];
	}
	int n{};
	cin>>n;
	while(n--)
	{
		int x{};
		cin>>x;
		For(i,0,3)
		{
			For(j,0,3)if(a[i][j]==x)a[i][j]=-1;
		}
	}
	int f{};
	For(i,0,3)
	{
		int ans{},res{};
		For(j,0,3)
		{
			if(a[i][j]==-1)ans++;
		}
		For(k,0,3)
		{
			if(a[k][i]==-1)res++;
		}
		if(ans==3 || res==3){f=1;break;}
	}
	if(f)cout<<"Yes\n";
	else{
		if((a[0][0]==-1 && a[1][1]==-1 && a[2][2]==-1) || (a[0][2]==-1 && a[1][1]==-1 && a[2][0]==-1 ))cout<<"Yes\n";
		else cout<<"No\n";
	}
	//system("pause");
	return 0;
}