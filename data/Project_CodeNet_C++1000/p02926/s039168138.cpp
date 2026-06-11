#include <bits/stdc++.h>

#define Y second
#define X first
#define pb push_back
#define mp make_pair

typedef long long ll;

using namespace std;

ll n, ans;
pair<ll, ll>a[200];

ll f(ll x, ll y){
	return x * x + y * y;
}

int main(){
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> a[i].X >> a[i].Y;
	}
	cout << '\n';
	for(ll k = 1; k <= 1000; k++){
		random_shuffle(a + 1, a + 1 + n);
		ll x, y;
		x = y = 0;
		for(ll i = 1; i <= n; i++){
			if(f(x + a[i].X, y + a[i].Y) > f(x, y)){
				x += a[i].X;
				y += a[i].Y;
			}
		}
		ans = max(ans, f(x, y));
	}
	printf("%.10f", sqrt(ans));
}