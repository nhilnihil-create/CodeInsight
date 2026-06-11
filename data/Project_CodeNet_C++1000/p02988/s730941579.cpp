#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i,n) cin >> p[i];
	int counts = 0;
	rep(i,n-2){
		if(p[i+1]>p[i] && p[i+1] < p[i+2]) counts++;
		if(p[i+1]<p[i] && p[i+1] > p[i+2]) counts++;
	}
	cout << counts << endl;
}

// cout << fixed << setprecision(15) <<  << endl;