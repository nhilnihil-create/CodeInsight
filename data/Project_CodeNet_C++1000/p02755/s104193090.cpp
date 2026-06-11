#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int a,b;
	cin >> a >> b;
	for(int i = 0;i < 100000;i++){
		if(i == 99998 && (int(i*0.08) != a || int(i*0.1) != b)){
			cout << -1 << endl;
			break;
		}
		if(int(i*0.08) == a && int(i*0.1) == b){
			cout << i << endl;
			break;
		}
	}
}