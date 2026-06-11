#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int n;
	cin >> n;
	float cnt = 0.0;
	for(int i = n;i > 0;i--){
		if(i % 2 == 1){
			cnt++;
		}
	}
	cout << float(cnt) / float(n) << endl;
}