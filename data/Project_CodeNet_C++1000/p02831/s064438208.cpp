#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
	int a,b;cin>>a>>b;
	cout<<(a*b)/(__gcd(a,b));
	
}