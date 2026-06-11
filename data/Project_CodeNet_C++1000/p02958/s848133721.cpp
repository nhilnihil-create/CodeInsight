#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,cnt=0;
	int p;
	cin >> n;
	for(int i = 1; i < n; i++){
		cin >> p;
		if(p != i){
			cnt++;
		}
	}
	cout << (cnt<=2?"YES":"NO") << endl;
	return 0;
}