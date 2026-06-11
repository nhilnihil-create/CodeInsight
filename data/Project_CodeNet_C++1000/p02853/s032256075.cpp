/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
#define si(x)     scanf("%d", &x)
#define sll(x)    scanf("%lld", &x)
#define ssll(x,y)    scanf("%lld %lld", &x ,&y)
#define sd(x)     scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100005
#define maxn 	  200002
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main ()
{
		ios::sync_with_stdio(0);
		cin.tie(0);
		//CODE TONOY
		int x,y;
		cin >> x >> y;
		if(x==1 && y==1) 
		{
			cout << 1000000 << endl;
			return 0;
		}
		int mon = 0;
		if (x==1) mon+=300000;
		else if (x==2) mon+=200000;
		else if (x==3) mon+=100000;
		else mon+=0;
		if (y==1) mon+=300000;
		else if (y==2) mon+=200000;
		else if (y==3) mon+=100000;
		else mon+=0;
		cout << mon << endl;
		return 0;  
}  
