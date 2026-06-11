/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
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
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		for (int i=0 ;  i<n  ; i++)
		scanf("%d",&a[i]);
		int ans = 0;
		for (int i=0 ; i<n ; i++)
		{
			for (int j=0 ; j<n ; j++)
			if(i==j) continue;
			else
			{
				ans+=a[i]*a[j];
			}
		}
		printf("%d",ans/2);
		return 0;
}  
