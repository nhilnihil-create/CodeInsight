#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	ll a;
	double b;
	cin >> a >> b;
	ll c = b*100 + 0.1;
	ll d = a*c;
	ll e = d/100;
	cout << e << endl;
}