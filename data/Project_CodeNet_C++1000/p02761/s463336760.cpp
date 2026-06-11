#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n, -1);
	rep(i, m){
		int s, c;
		cin >> s >> c;
		if(s > n){
			cout << -1 << endl;
			return 0;
		}
		if(a[s-1] != -1 && a[s-1] != c){
			cout << -1 << endl;
			return 0;
		}
		a[s-1] = c;
	}
	v1 answer(n);
	if((a[0] == 0 && n == 1 && a.size() == 1)|| a[0] == -1 && n==1 &&a.size() == 1){
		cout << 0 << endl;
		return 0;
	}
	if(a[0] == 0){
		cout << -1 << endl;
		return 0;
	}else if(a[0] == -1){
		answer[0] = 1;
	}else{
		answer[0] = a[0];
	}
	for(int i = 1; i< n; i++){
		if(a[i] == -1){
			answer[i] = 0;
		}else{
			answer[i] = a[i];
		}
	}
	rep(i, n){
		cout << answer[i];
	}
	cout << endl;
}
