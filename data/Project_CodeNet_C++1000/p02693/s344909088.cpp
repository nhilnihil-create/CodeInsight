#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
	int k;
	cin >> k;
	int a, b;
	cin >> a >> b;
	if(b/k > (a-1) / k){
		cout << "OK" << endl;
	}else{
		cout << "NG" << endl;
	}
	return 0;
}
