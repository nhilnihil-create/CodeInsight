#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	ll n;
	cin >> n;
	ll ans = 0;
	ans += n/500*1000;
	n -= ans/2;
	ans += n/5*5;
	cout<<ans<<endl;
}
