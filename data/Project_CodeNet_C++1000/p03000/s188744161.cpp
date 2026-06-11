#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,x;
	cin >> n >> x;
	vector<int> l(n);
	rep(i,n) cin >> l[i];
	int counts = 1;
	int wa = 0;
	rep(i,n){
		wa += l[i];
		if(wa <= x) counts++;
	}
	cout << counts << endl;
}

// cout << fixed << setprecision(15) <<  << endl;