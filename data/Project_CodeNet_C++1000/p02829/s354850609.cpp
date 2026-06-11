#include <bits/stdc++.h>
using namespace std;

int A, B;

int main () {
	cin >> A >> B;
	if (A==1){
		if (B==2){
			cout << "3";
		} else {
			cout << "2";
		}
	} else if (A==2){
		if (B==1){
			cout << "3";
		} else {
			cout << "1";
		}
	} else if (A==3){
		if (B==1){
			cout << "2";
		} else {
			cout << "1";
		}
	}
}