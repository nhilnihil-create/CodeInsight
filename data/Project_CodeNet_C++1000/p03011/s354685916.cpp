#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int p,q,r;
	cin >> p >> q >> r;
	cout << min(p+r,min(p+q,q+r)) << endl;
}

// cout << fixed << setprecision(15) <<  << endl;