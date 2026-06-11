#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<sstream>
#define ll long long
const int inf = 0x3f3f3f3f;
const int N = 1e-6;
const ll M = 1e9+7;

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	ll ans = 0;
	ll a;
	double b;
	cin>>a>>b;
         b+=(1e-6);
	ans=b*100;
	ans = a*ans/100;
	cout<<ans<<endl;
	return 0;
}