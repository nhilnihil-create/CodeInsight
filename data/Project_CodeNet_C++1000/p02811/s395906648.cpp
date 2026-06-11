#include<bits/stdc++.h>
#define con continue
#define pb push_back
#define fi first
#define se second
#define fr front()
#define one 1.0
#define inf 1000000000000000000
#define ret return
#define all(vl) vl.begin(),vl.end()
#define sor sort 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef map<ll,ll>::iterator itll;
typedef long double ld;
typedef map<ll,ll> mapll;
int main()
{
	ll a,b;
	cin>>a>>b;
	ll k = a*500;
	if(k>=b)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}