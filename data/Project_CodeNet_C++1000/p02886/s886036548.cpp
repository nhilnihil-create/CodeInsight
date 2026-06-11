#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;
int main() {
	int n;
	cin >> n;
	vector<int> d(n);
	rep(i,n) cin >> d[i];
	int sum=0;
	rep(i,n){
		for(int j=i+1;j<n;j++){
			sum+=d[i]*d[j];
		}
	}
	cout << sum << endl;
	return 0;
}
