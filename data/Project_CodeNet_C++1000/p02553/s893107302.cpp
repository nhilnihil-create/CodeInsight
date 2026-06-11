#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;

#define rep(i,n)	for(ll i=0;i<(n);i++)
#define SZ(x) ((ll)x.size())
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define F first
#define S second
#define int ll
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll MOD = INT_MAX;
const double PI = acos(-1);

void openfile(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
}


signed main(){
	IOS
	int a,b,c,d;	cin >> a >> b >> c >> d;
	int x[4];
	x[0] = a*c;
	x[1] = a*d;
	x[2] = b*c;
	x[3] = b*d;
	sort(x,x+4,greater<int>());
	cout << x[0] << endl;
}
