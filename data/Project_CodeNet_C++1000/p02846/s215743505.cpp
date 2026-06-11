#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll t1, t2, a1, a2, b1, b2;
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

	ll x = (a1 - b1) * t1;
	ll y = (a2 - b2) * t2;

	cerr << x << "," << y << endl;

	if((x > 0 && y > 0) ||(x < 0 && y < 0) ){
		cout << 0 << endl;
		return 0;
	}

	if(x == 0){
		if(y == 0){
			cout << "infinity" << endl;
			return 0;
		}else{
			cout << 1 << endl;
			return 0;
		}
	}

	if(x == -y){
		cout << "infinity" << endl;
		return 0;
	}

	if(x < 0){
		x = -x;
		y = -y;
	}

	ll d = x + y;
	if(d > 0){
		cout << 0 << endl;
	}else{
		if(x % (-d) == 0){
			cout << x / (-d) * 2<< endl; 
		}else{
			cout << x / (-d) * 2 + 1 << endl;
		}
	}
}
