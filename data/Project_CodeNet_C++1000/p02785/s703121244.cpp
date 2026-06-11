#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	priority_queue<ll> Q;
	int n, k;
	cin >> n >> k;
	rep(i, n){
		ll x;
		cin >> x;
		Q.push(x);
	}
	ll co = 0;
	int v =Q.size();
	rep(i, v){
		if(k > 0){
			k--;
			Q.pop();
			continue;
		}
		ll h = Q.top();
		co += h;
		Q.pop();
	}
	cout << co << endl;
}
