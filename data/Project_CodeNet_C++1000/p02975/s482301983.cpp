//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<utility>
#include<algorithm>
#include<cstring>
#include<sstream>
#include <iomanip>

typedef long long ll ;
typedef double db;
typedef unsigned long long ull ;
const double pi = 2*acos(0) ;

#define pf		  	printf
#define sf			  scanf
#define sf(a)		 scanf("%d",&a)
#define sfl(a)		scanf("%lld",&a)
#define sff(a,b)	 scanf("%d %d",&a,&b)
#define sffl(a,b)	scanf("%lld %lld",&a,&b)
#define pb(a)         push_back(a)
#define loop0(i,n)          for(int i=0;i<n;i++)
#define loop1(i,n)          for(int i=1;i<=n;i++)
#define loopab(a,b)       for(int i=a;i<=b;i++)
#define gcd(a, b)     __gcd(a, b)
#define lcm(a, b)     ((a)*((b)/gcd(a,b)))
#define sq(a)		   (a)*(a)
#define nw				"\n"
#define abs(x)		fabs(x)
#define pcase(z,x)     cout<<"Case "<<z<<": "<<x<<"\n"
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main()
{
	int i,n,x,r=0;
	cin>>n;
	for(i=0 ; i<n ; i++){
		cin>>x;
		r = r^x;
		}
	if(r)cout<<"No\n";
	else cout<<"Yes\n";
	return 0;
}