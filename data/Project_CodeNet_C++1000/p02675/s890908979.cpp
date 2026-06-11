#include<bits/stdc++.h>
using namespace std;

int main(){
	long long N;
	cin >> N;
	long long num = N%10;
	if(num == 3) {
		cout << "bon" << endl;
	} else if (num == 0 || num == 1 || num ==6 || num == 8) {
		cout << "pon" << endl;
	} else {
		cout << "hon" << endl;
	}
}
