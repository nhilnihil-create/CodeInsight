#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int n,m;
	cin >> n >> m;
	int list[n+m];
	for(int i = 0;i < n;i++){
		list[i] = 2;
	}
	for(int i = n;i < n+m;i++){
		list[i] = 1;
	}
	int cnt = 0;
	for(int i = 0;i < n+m;i++){
		for(int j = i+1;j < n+m;j++){
			if((list[i] + list[j]) % 2 == 0){
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}