#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int a,b,c;
	cin >> a >> b >> c;
	if(a == b && b == c){
		cout << "No" << endl;
	}else{
		if(a == b || b == c || c == a){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
}