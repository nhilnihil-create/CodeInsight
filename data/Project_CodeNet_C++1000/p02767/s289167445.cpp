#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
// typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ll long long 
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
#define lpri(n) printf("%lld",n)
#define pri(n) printf("%d",n)
#define pln() printf("\n")
#define priln(n) printf("%d\n",n)
#define lpriln(n) printf("%lld\n",n)
#define rep(i,init,n) for(int i=init;i<n;i++)
#define pb push_back     
#define mp make_pair
#define F first
#define S second
#define gcd __gcd
#define inf INT_MAX
#define ninf INT_MIN   
#define linf LLONG_MAX
#define lninf LLONG_MIN   
const ll mod = 1e9+7;
const int N = 2e5+4;

int main()
{
	int n; scn(n);

	int a[n],x=0;

	int val=0,temp=0;

	rep(i,0,n)
	scn(a[i]),x+=a[i];

	x/=n; 

	rep(i,0,n)
	{
		val += (x-a[i])*(x-a[i]);

		temp += (x+1-a[i])*(x+1-a[i]);
	}

	pri(min(val,temp));

	return 0;
}