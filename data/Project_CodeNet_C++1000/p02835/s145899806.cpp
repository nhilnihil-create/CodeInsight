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
        ll a,b,c;
        sll(a),sll(b),sll(c);
        if(a+b+c>=22) cout << "bust" << endl;
        else cout << "win" << endl;
		return 0;
}
