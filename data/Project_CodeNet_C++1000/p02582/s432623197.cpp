#include <bits/stdc++.h>
using namespace std;

string A;

int main(){
	cin >> A;
	bool ok1 = false;
	for (int i = 0; i < A.size(); i ++){
		if (A[i] == 'R'){
			ok1 = true;
		}
	}

	bool ok2 = false;
	for (int i = 1; i < A.size(); i ++){
		if (A[i] == 'R' && A[i - 1] == 'R'){
			ok2 = true;
		}
	}

	bool ok3 = (A[2] == 'R' && A[1] == 'R' && A[0] == 'R');

	if (ok3){
		cout << "3\n";
	}else if (ok2){
		cout << "2\n";
	}else if (ok1){
		cout << "1\n";
	}else{
		cout <<"0\n";
	}
}