#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	ll v;
	ll l;
	cin >> l;
	v = l*l*l;
	double a;
	a = v / 27.0;
	printf("%lf\n", a);
}
