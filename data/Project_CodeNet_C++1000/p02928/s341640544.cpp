 //Dragon_warrior7(IITK)
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define umap unordered_map
#define uset unordered_set
#define ll long long
#define lll long long
#define pb push_back
#define nl cout << '\n'
#define sor(x) sort(x.begin(), x.end())
#define rev(v) reverse(v.begin(), v.end())
#define lb(v, temp) lower_bound(v.begin(), v.end(), temp)
#define ub(v, temp) upper_bound(v.begin(), v.end(), temp)
#define fi first
#define se second
#define llmax 1000000000000000000
#define pll pair<ll, ll> 
#define ull unsigned ll
#define vll vector<ll> 
#define rub cout << "\n------------------------------------\n"
#define deb(x) cerr<<#x<<' '<<'='<<' '<<x<<'\n'
#define fo(i,a,b) for(int i=a;i<b;i++)
#define Lets_be_precise cout<<fixed<<setprecision(10)
//typedef  tree < int ,  null_type ,  greater<int> ,  rb_tree_tag ,  tree_order_statistics_node_update > oset;
const int mod=1e9+7;
// ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// ll modInverse(ll a){return power(a,mod-2);}
ll n,m,a,b,c,k,temp,x,y;
const int MAXN=100000+11;
void read(vector<ll> &v)
{
	for (int i = 0; i < v.size(); i++)
	cin>>v[i];
}
//#define cerr if(false)cerr//uncomment to remove cerr from program...
void solveforthiscase(const int & test)
{//deb(test);
cin>>n>>k;
vll v(n);
read(v);
ll count=0;
ll g[3000];
for(int i=0;i<n;i++)
{
    g[v[i]]=llmax;
for(int j=0;j<i;j++)
{
    if(v[j]>v[i])
    count++;
}
}
sor(v);
for(int i=0;i<n;i++)
{
    g[v[i]]=min(g[v[i]],n-i-1);
}
count+=(k-1)*count;
for(int i=0;i<n;i++)
{
    count+=((((k-1)*(k))/2)%mod*g[v[i]])%mod;
    count%=mod;
}
cout<<count;
return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	Lets_be_precise;
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
// 	cin>>test;
    for(int i=1;i<=test;i++)
    {
        solveforthiscase(i);
    }
}