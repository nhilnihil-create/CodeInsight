//HEADER FILES AND NAMESPACES

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>   
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 

// DEFINE STATEMENTS

#define num1 1000000007
#define num2 998244353
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define REPd(i,a,n) for(ll i=a; i>=n; i--)
#define pb push_back
#define pob pop_back
#define f first
#define s second
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define all(x) x.begin(), x.end()
#define M_PI 3.14159265358979323846
#define epsilon (double)(0.00000000001)

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());  // FOR RANDOM NUMBER GENERATION

// DEBUG FUNCTIONS 
#ifndef ONLINE_JUDGE

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

template<typename T>
void __p(T a) {
	cout<<a;
}
template<typename T, typename F>
void __p(pair<T, F> a) {
	cout<<"{";
	__p(a.first);
	cout<<",";
	__p(a.second);
	cout<<"}";
}
template<typename T>
void __p(std::vector<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it<a.end(); it++)
		__p(*it),cout<<",}"[it+1==a.end()];
}
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
	__p(a1);
	__p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";
	__p(arg1);
	cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(;; i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	const char *comma=names+i;
	cout.write(names,comma-names)<<" : ";
	__p(arg1);
	cout<<" | ";
	__f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#define error(...)
#endif

// DEBUG FUNCTIONS END 

// CUSTOM HASH TO SPEED UP UNORDERED MAP AND TO AVOID FORCED CLASHES
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll mod_exp(ll a, ll b, ll c)
{
	ll res=1;   a=a%c;
	while(b>0)
	{
		if(b%2==1)
			res=(res*a)%c;
		b/=2;
		a=(a*a)%c;
	}
	return res;
}
ll mymod(ll a,ll b)
{
		return ((a%b)+b)%b;
}
ll gcdExtended(ll,ll,ll *,ll *);
ll modInverse(ll a, ll m) 
{ 
		ll x, y; 
		ll g = gcdExtended(a, m, &x, &y); 
		g++;   //this line was added just to remove compiler warning
		ll res = (x%m + m) % m;
		return res;
} 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
		if (a == 0) 
		{ 
				*x = 0, *y = 1; 
				return b; 
		} 
		ll x1, y1; 
		ll gcd = gcdExtended(b%a, a, &x1, &y1);
		*x = y1 - (b/a) * x1; 
		*y = x1; 
		return gcd; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());  // FOR RANDOM NUMBER GENERATION
	ll n;
	cin>>n;
	ll find = 1;
	REP(i,0,n)
	{
		ll a;
		cin>>a;
		if(a==find)
		{
			find++;
		}
	}
	if(find>1)
	cout << n - find + 1 << "\n";
	else
	cout<<"-1\n";
	return 0;
}



