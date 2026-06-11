#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	int n;
	cin >> n;
	bool b = true;
	map<ll, int> a;
	rep(i, n){
		ll x;
		cin >> x;
		if(a.find(x) != a.end()){
			cout << "NO" << endl;
			b = false;
			break;
		}else{
			a[x] = 1;
		}
	}
	if(b) cout << "YES" << endl;
}
