#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	string s,t;
	int cnt = 0;
	cin >> s >> t;
	for(int i = 0;i < 3;i++){
		if(s[i] == t[i]){
			cnt++;
		}
	}
	cout << cnt << endl;
}