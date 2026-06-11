#include <bits/stdc++.h>
using namespace std;

#define len(s) int(s.size())
#define res(x) cout<<((x)?"unsafe\n":"safe\n")
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef long double ld;

ll mod = 1e9+7;

void solution() {
	int k, n, x;
	cin >> k >> n;

	bool existk = false;
	vector<bool> a(110, false);
	
	for(int i = 0; i < n; ++i) {
		cin >> x;
		a[x] = true;
		if(x == k) {
			existk = true;
		}
	}

	if(existk == false) {
		cout << k;
		return;
	}
	int up = 200, down = -200;
	for(int i = k; i <= 101; ++i) {
		if(a[i] == false) {
			up = i;
			break;
		}
	}
	for(int i = k; i >= 0; --i) {
		if(a[i] == false) {
			down = i;
			break;
		}
	}

	//cout << "Up: " << up << ", Down: " << down;

	cout << (abs(k-down) <= abs(k-up) ? down : up);

	
}

int main(){
	
	int t = 1;
	//cin >> t;
	
	while(t--)
		solution();
	
	return 0;
}
