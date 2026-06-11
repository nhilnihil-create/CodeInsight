#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> ans(n,1);
	rep(i,k){
		int d;
		cin >> d;
		rep(j,d){
			int a;
			cin >> a;
			ans[a-1] = 0;
		}
	}
	int sum = 0;
	rep(i,n) sum += ans[i];
	cout << sum << endl;
}