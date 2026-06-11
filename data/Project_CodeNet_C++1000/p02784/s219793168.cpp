#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int h,n;
	cin >> h >> n;
	vector<int> a(n);
	a = forintinput(n);
	int sumA = 0;
	for(int i = 0;i < n;i++){
		sumA += a[i];
	}
	if(sumA >= h){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}