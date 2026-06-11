#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	int sum = 0;
	vector<int> d(n);
	rep(i,n) cin >> d[i];
	rep(i,n)rep(j,n){
		if(i == j) continue;
		sum += d[i]*d[j];
	}
	cout << sum/2 << endl;
}