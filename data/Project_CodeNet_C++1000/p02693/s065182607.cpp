#include <bits/stdc++.h>
using namespace std;
int intinput() {
	int x;
	cin >> x;
	return x;
}
vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int k;
	int a,b;
	cin >> k;
	int k2 = k;
	cin >> a >> b;
	int cnt = 2;
	while(k < a){
		k = k2*cnt;
		cnt++;
	}
	if(k > b){
		cout << "NG" << endl;
	}else{
		cout << "OK" << endl;
	}
}