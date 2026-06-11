#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
signed main(){
	int A, B, C, K;
	cin >> A >> B >> C >> K;
	//a < b < c
	bool flg = false;
	for(int i = 0; i < K; i++){
		if(B <= A){
			B*=2;
		}else if(C <= B){
			C*=2;
		}
		if(A < B && B < C){
			flg = true;
		}
	}
	cout << (flg?"Yes":"No") << endl;

 
	return 0;
}