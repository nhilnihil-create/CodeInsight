#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x;
	for(int i = 0;i < n;i++){
		int ia;
		cin >> ia;
		x.push_back(ia);
	}
	return x;
}
int main(){
	int n,m;
	cin >> n >> m;
	vector<int> a(m);
	int cnt = 0;
	for(int i = 0;i < m;i++){
		cin >> a[i];
		cnt += a[i];
	}
	if(cnt > n){
		cout << -1 << endl;
		return 0;
	}else{
		cout << n - cnt << endl;
	}
}