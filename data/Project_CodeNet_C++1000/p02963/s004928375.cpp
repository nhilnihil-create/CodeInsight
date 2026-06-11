#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using Graph = vector< vector<int> >;

int main(){
	ll S; cin >> S;
	ll sq = 0;
	ll x1 = 1000000000;
	ll y1 = 1;
	ll x2 = (x1-S%x1)%x1;
	ll y2 = (S+x2)/x1;
	cout << 0 << " " << 0 << " " << x1 << " " << y1 << " " << x2 << " " << y2;
	cout << endl;
	return 0;
}