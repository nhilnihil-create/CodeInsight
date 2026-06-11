#include <bits/stdc++.h>
using namespace std;

int main(){
	int check = false;
	int n;
	cin >> n;
	for(int i=1;i < 10;i++){
		if(n % i ==0){
			if(n / i < 10)check = check || true;
		}
	}
	if(check) cout << "Yes" << endl;
	else cout << "No" << endl;
}