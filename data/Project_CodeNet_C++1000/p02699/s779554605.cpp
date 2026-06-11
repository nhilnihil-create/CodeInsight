#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int s,w;
	cin >> s >> w;
	if(s <= w){
		cout << "unsafe" << endl;
	}else{
		cout << "safe" << endl;
	}
}