#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	string n;
	cin >> n;
	int cnt = 0;
	for(int i = 0;i < 3;i++){
		if(n[i] == '7'){
			cnt++;
		}
	}
	if(cnt != 0){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}