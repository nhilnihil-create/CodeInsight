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
	int n,k;
	cin >> n >> k;
	vector<int> p;
	int cnt = 0;
	p = forintinput(n);
	sort(p.begin(), p.end());
	for(int i = 0;i < k;i++){
		cnt += p[i];
	}
	cout << cnt << endl;
}