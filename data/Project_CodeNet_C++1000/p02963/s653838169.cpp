#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mem0(x) memset(x,0,sizeof(x))
#define meminf(x) memset(x,0x3f,sizeof(x))
#define VI vector<int>
#define VL vector<ll>
using namespace  std;

const int N = 1e3+5;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll s; cin >> s;
	if (s == 1000000000000000000) {
		cout << 0 << " " << 0 << " " << 1000000000 << " " << 0 << " " << 0 << " " << 1000000000; 
        return 0;
	}
	ll x3 = 1000000000 - (s % 1000000000);
	ll y3 = s / 1000000000 + 1;

	cout << 0 << " " << 0 << " " << 1000000000 << " " << 1 << " " << x3 << " " << y3;
}