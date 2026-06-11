#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define F first
#define S second
#define vll vector<ll>
#define fast ios:: sync_with_stdio(false),cin.tie(0);
#define COUT cout<<fixed<<setprecision(12)
#define SET set<ll,greater<ll>>gquiz
#define ITERATOR set<ll,greater<ll>> :: iterator itr
#define V vector<ll>vector
#define sz size()
//#define A vector<pair<ll,ll>>vect
ll N=100000,M=100000;
#define B vect.push_back(make_pair(N,M));
ll MOD=1000000007;
 
bool isprime(ll n){if(n==1 || (n!=2 && n%2==0))return false; if(n==2)return true; 
		for(ll i=3;i<=sqrt(n);i+=2)if(n%i==0)return false; return true; }
ll gcd(ll a,ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

void solve()
{
	ll x,y,z;
	cin>>x>>y>>z;
	cout<<z<<" "<<x<<" "<<y;
}
int main()
{
	fast;
	ll t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}