#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll a, v, b, w, t;
	cin >> a >> v >> b >> w >> t;

	if(w > v){
		cout << "NO" << endl;
		exit(0);
	}

	if(abs(b - a) <= (v - w) * t){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}

}
