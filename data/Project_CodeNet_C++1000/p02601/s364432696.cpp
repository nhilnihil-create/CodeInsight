#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int A, B, C;
	cin >> A >> B >> C;
	
	int k;
	cin >> k;
	
	if(C > B && B > A){
		cout << "Yes" << endl;
		return 0;
	}
	
	while(B <= A){
		if(B > A){
			break;
		}
		if(k == 0) break;
		B *= 2;
		k--;
	}
	if(k == 0 && C < B){
		cout << "No" << endl;
		return 0;
	}
	if(k > 0) {	
		while(C <= B){
			if(C > B){
				break;
			}
			if(k == 0) break;
			C *= 2;
			k--;
		}
	}
	if(B > A && C > B){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}