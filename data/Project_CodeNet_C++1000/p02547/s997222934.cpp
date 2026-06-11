/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
#define sd(x)     scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100005
#define maxn 	  200005
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	while(n--)
	{
		int x,y;
		cin >> x >> y;
		if(x==y) cnt++;
		else cnt = 0;
		if(cnt==3) break;
	}
	if(cnt == 3) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
