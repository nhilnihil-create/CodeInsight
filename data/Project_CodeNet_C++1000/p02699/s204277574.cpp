#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define lf long double
#define vi vector<int>
#define vl vector<long long int>
#define pii pair <int,int>
#define pll pair <long long int, long long int>
#define vpii vector< pair<int,int> >
#define vpll vector < pair <long long int,long long int> >
#define MOD 1000000007
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define in insert
#define all(x) x.begin(),x.end()
#define zapp ios::sync_with_stdio(false);cin.tie(0)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {if (y < 0) return 1; ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll inv(ll x) {return power(x, MOD - 2);}
const int MAXN = 1e5 + 5;
//const bool is_in = container.find(element) != container.end();
int main()
{
	zapp;
	ll s,w;
	cin>>s>>w;
	if(w>=s)
		cout<<"unsafe";
	else
		cout<<"safe";

	return 0;
}