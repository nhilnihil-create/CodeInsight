#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int digit = n%10;
	if(digit == 2 || digit == 4 || digit == 5 || digit == 7 || digit == 9){
		cout << "hon"; 
	}
	else if(digit == 0 || digit == 1 || digit == 6 || digit == 8){
		cout << "pon";
	}
	else{
		cout << "bon";
	}
}
