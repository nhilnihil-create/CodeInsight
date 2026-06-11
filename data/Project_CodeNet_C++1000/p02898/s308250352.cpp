#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	rep(i,n) cin >> h[i];
	int sum = 0;
	rep(i,n) if(h[i] >= k) sum++;
	cout << sum << endl;
}