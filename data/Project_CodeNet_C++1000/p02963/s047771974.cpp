#include<bits/stdc++.h>
#define cs const
#define pb push_back
#define y1 y_1
using namespace std;
typedef long long ll;
int main(){
	#ifdef FSYolanda
	freopen("1.in","r",stdin);
	#endif
	ll S; scanf("%lld",&S);
	ll t = sqrt(S);
	if(1ll * t * t == S){
		cout << 0 << " " << 0 << " " << t << " " << 
		0 << " " << 0 << " " << t << '\n';
		return 0;
	} ++t;
	ll x2 = t, y1 = t;
	ll r = t * t - S;
	ll x1 = 1, y2 = r;
	if(t < 1e9){
		if(r & 1) ++x2, --y1, --r;
		x1 = 2, y2 = r >> 1; 
		cout << 0 << " " << 0 << " " << x1 << 
		" " << y1 << " " << x2 << " " << y2;
		return 0;
	} else{
		if(r <= 1e9){
			cout << 0 << " " << 0 << " " << x1 << 
			" " << y1 << " " << x2 << " " << y2;
			return 0;
		} y1 = t - 1;
		r = t * (t - 1) - S;
		y2 = r;
		cout << 0 << " " << 0 << " " << x1 << 
		" " << y1 << " " << x2 << " " << y2;
	}
	return 0;
}