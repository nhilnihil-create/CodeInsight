#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int k,x;
	cin >> k >> x;
	if(k*500 >= x){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}