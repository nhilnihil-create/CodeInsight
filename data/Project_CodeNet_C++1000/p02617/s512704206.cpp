#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define gadd(x,y) x=add(x,y)
#define gmul(x,y) x=mul(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	ll tot = 0;
	rep(i,1,n+1)tot += 1LL*(n-i+1)*(n-i+2)/2;
	rep(i,0,n-1){
		int u,v;
		cin >> u >> v;
		if(u > v)swap(u,v);
		tot -= 1LL * u * (n + 1- v);
	}
	cout << tot << '\n';
}
