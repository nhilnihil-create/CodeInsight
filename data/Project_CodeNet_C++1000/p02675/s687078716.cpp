#include <bits/stdc++.h>
#include <string>
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
	int n;
	n = intinput();
	if(n % 10 == 2||n % 10 == 4||n % 10 == 5||n % 10 == 7||n % 10 == 9){
		cout << "hon" << endl;
	}else if(n % 10 == 0||n % 10 == 1||n % 10 == 6||n % 10 == 8){
		cout << "pon" << endl;
	}else{
		cout << "bon" << endl;
	}
}