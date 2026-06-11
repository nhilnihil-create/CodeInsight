#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <stack>
using namespace std;
#define ll long long
#define pb push_back
#define pp pair<long long,long long>
#define ppp pair<pair<long long,long long>,long long>
#define f firsta
#define s second
#define pd pair<double,long long>
int main() {
	ll t,n,i,j,k,l,m;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll p;
	t=1;
	//cin>>t;
	while (t--) {
		double d,s,t,c;
		cin>>d>>s>>t;
		c=d/s;
		if (c<=t)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}