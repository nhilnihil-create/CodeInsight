//compiledef
#include <bits/stdc++.h>
#define rep(i, n) for(i=0;i<(n);i++)
#define per(i, n) for(i=(n);i>0;i--)
#define repx(i, n, x) for(i=(x);i<(n);i++)
#define xper(i, n, x) for(i=(n);i>(x);i--)
#define pback push_back

//c++def
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;

int main(){
	int f, s, n;
	vector<int> a;
	int i, ho;
	cin >> n;
	rep(i, n){
		cin >> ho;
		a.pback(ho);
	}
	vector<int> b = a;
	sort(b.begin(), b.end());
	f = b[n-1];
	s = b[n-2];
	rep(i, n){
		if(a[i] == f) cout << s << endl;
		else cout << f << endl;
	}
}
