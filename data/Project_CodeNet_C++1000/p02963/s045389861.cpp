#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int32_t main()
{
	int s=in();
	cout<<"0 0 ";
	int x2=1;
	int sq=sqrt(s);
	if(sq*sq==s)
	{
		cout<<"1 "<<sq<<" "<<sq<<" 0";
		return 0;
	}
	
	int y3=(sq+1)*(sq+1)-s;
	cout<<"1 "<<sq+1<<" "<<sq+1<<" "<<y3;
	
}
