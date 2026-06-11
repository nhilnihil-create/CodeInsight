#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int A, B, C, K;
	string result;
	cin >> A >> B >> C >> K;

	while(K > 0){
		
		if(B <= A || C <= B){
			if(B <= A){
				B *= 2;
			}
			else{
				C *= 2;
			}
			K--;
		}
		else{
			break;
		}
	}
	
	result = (A < B && B < C) ? "Yes" : "No";
	cout << result;
	return 0;
}
