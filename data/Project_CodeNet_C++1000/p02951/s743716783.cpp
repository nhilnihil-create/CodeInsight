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
	int a,b,c;
	cin >> a >> b >> c;
	if(c - (a - b) <= 0){
		cout << 0 << endl;
	}else{
		cout << c - (a - b) << endl;
	}
}