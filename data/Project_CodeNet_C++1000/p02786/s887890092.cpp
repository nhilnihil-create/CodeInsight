#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll n)
{
	if(n==1) return 1;
	else return f(n/2)*2+1;
}
int main()
{
	ll h;
	cin>>h;
	cout<<f(h)<<"\n";
	return 0;
} 