#include <bits/stdc++.h>
using namespace std;

int Euclidean(int A, int B){
	int C = 0;
	if(A == B)return A;
	if(A > B){
		C = A % B;
		if(C == 0) return B;
		else return Euclidean(B, C);
	}
	else{
		C = B % A;
		if(C == 0) return A;
		else return Euclidean(A, C);
	}
}

int main(){
	int K;
	cin >> K;
	int ans = 0;
	for(int x = 1;x<=K;x++){
		for(int y = 1;y<=K;y++){
			for(int z = 1;z<=K;z++){
				int gcd = Euclidean(x, Euclidean(y, z));
				ans += gcd;
			}
		}
	}
	cout << ans << endl;
}
