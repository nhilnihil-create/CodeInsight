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
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	while(a > 0){
		c -= b;
		if(c <= 0){
			cout << "Yes" << endl;
			return 0;
		}
		a -= d;
	}
	cout << "No" << endl;
}