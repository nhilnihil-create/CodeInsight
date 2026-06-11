#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#ifdef _debug
#define dout(i) cout << #i << ' ' << i << ' '
#else 
#define dout(i) //
#endif
#define sp(i) (i>n ? i-n : i == 0 ? n : i)
using ll = long long;
using ull = unsigned long long;
using ul = unsigned;
const int maxn = 200001;
const int maxm = maxn * 100;
int a[maxn], b[maxn], n;
int togo[maxm], tlen;
bool ok(int p){
	p = sp(p);
	return b[p] > max(b[p-1] + b[p+1], a[p]);
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i)cin >> a[i];
	for(int i = 1;i <= n;++i)cin >> b[i];
	b[n+1] = b[1];b[0] = b[n];
	ll res = 0;
	for(int i = 1;i <= n;++i)if(ok(i))togo[tlen++] = i;
	for(int j = 0;j < tlen;++j){
		int &i = togo[j];
		int st = (b[i] - a[i]) / (b[i-1]+b[i+1]);
		res += st;
		b[i] -= st * (b[i-1] + b[i+1]);
		b[1] = b[n+1] = min(b[1], b[n+1]);
		b[0] = b[n] = min(b[0], b[n]);
		if(ok(i+1))togo[tlen++] = sp(i+1);
		if(ok(i-1))togo[tlen++] = sp(i-1);
	}
	for(int i = 1;i <= n;++i){
		if(a[i] != b[i])res = -1;
	}
	cout << res << '\n';
}