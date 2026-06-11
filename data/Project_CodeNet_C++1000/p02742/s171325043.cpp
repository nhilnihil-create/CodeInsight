#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

v1 move_h{1, 1, -1, -1};
v1 move_w{1, -1, 1, -1};
ll t = 0;
ll H, W;

/*void kaku(ll h, ll w, v2& b){
	if(h < 0 || w < 0 || h >= H || w >= W) return;
	if(b.at(h).at(w) == 1) return;
	t++;
	b.at(h).at(w) = 1;
	rep(i, 4){
		ll n_h = h + move_h.at(i);
		ll n_w = w + move_w.at(i);
		kaku(n_h, n_w, b);
	}
}*/

int main(){
	/*cin >> H >> W;
	v2 b(H, vector<int>(W, 0));
	kaku(0, 0, b);
	cout << t << endl;*/
	cin >> H >> W;
	int a = H%2;
	if(H == 1 || W == 1){
		cout << 1 << endl;
		return 0;
	}
	if(W%2 == 0) cout << W/2*H << endl;
	if(W%2 == 1) cout << W/2*H + H/2 + H%2 << endl;
}
