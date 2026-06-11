#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int,int>;

int main(){
	int k,n;
	cin >> k >> n;
	vector<int> a(n);
	rep(i,n){
		cin >> a[i];
	}
	vector<int> ans(n);
	for(int i=1;i<n;i++){
		ans[i] = a[i] - a[i-1];
	}
	ans[0] = k-a[n-1]+a[0];
	int maxim = 0;
	rep(i,n){
		if(maxim < ans[i]) maxim = ans[i];
	}
  //cout << a[n-1] << endl;
	cout << k-maxim << endl;
}