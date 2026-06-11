#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	 
	long long int X; cin >> X;
	for(long long A = -200; A <= 200; A++){
		for(long long B = -200; B <= 200; B++){
			auto a = A*A*A*A*A, b = B*B*B*B*B;
			if(a - b == X) {
				cout << A << " " << B << endl;
				return 0;
			}
		}
	}




    
}
