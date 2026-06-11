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
	vector<int> x(5);
	x = forintinput(5);
	int cnt = 0;
	for(int i = 0;i < 5;i++){
		if(x[i] == 0){
			cnt = i;
		}
	}
	cout << cnt+1 << endl;
}