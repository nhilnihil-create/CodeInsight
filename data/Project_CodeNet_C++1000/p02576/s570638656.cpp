#include <bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) rep2(i,0,n)
#define FOR(i) for(cin>>i;i>0;i--)
#define elif else if
#define pb push_back
#define ll long long
#define mp make_pair
#define all(x) x.begin(),x.end()
#define re(x) {cout<<x<<endl;return 0;}
//#define x first
//#define y second

using namespace std;
int a,b,c;
int main()
{
	cin>>a>>b>>c;
	re((a/b+(a%b!=0))*c)
	return 0;}