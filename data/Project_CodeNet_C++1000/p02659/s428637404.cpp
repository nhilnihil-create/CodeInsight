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
const int N = 1e3+50;
const ll M = 1e9+7;

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	ll ans = 0;
	ll a;
	string b;
	cin>>a>>b;
	ans = (b[0]-'0')*100 + (b[2]-'0')*10 + (b[3]-'0');
	ans = a*ans/100;
	cout<<ans<<endl;
	return 0;
}