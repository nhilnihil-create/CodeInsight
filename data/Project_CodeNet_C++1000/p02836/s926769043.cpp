/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
#define si(x)     scanf("%d", &x)
#define sll(x)    scanf("%lld", &x)
#define sd(x)     scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100000
#define maxn 	  200002
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007
#define vi(a)	  vector<ll>a
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


int main ()
{
		ios::sync_with_stdio(0);
		cin.tie(0);
		//CODE TONOY
		string s;
		cin >> s;
		string s2 = s;
		ll cnt = 0;
		reverse(s2.begin(),s2.end());
		for (int i=0 ; i<(int)s.length() ; i++)
		{
			if(s[i]!=s2[i])
			cnt++;
			//cerr << imie(cnt);
			//cerr << endl;
		}
		cout << cnt/2 << endl;
		
		return 0;
}
