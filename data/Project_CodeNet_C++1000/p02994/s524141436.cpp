#include<algorithm>
#include<iostream>
#include<iomanip>
#include<numeric>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
int main() {
	int n,l,pai=0,mii=1000000000;
	cin >> n >> l;
	vector<int> r(n);
	for(int i = 0; i < n; ++i) {
		r[i] = l + i;
		pai += r[i];
		mii=min(mii,abs(r[i]));
	}
	int mi = 1000000000;
	for(int i = 0; i < n; ++i) {
		int a = r[i];
		if(pai-(pai-abs(a)) <=abs(mi) )
			mi = r[i];
	}
	cout << pai - mi << endl;
}