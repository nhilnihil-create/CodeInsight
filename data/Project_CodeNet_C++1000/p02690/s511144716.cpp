#include <bits/stdc++.h>
using namespace std;

int main(){
	long long X;
	cin >> X;
	long long A = 140, B = 140;
	for(long i=-120;i<120;i++){
		for(long j=-120;j<120;j++){
			if(i*i*i*i*i - j*j*j*j*j == X){
				A = i;
				B = j;
				break;
			}
		}
		if(A != 140)break;
	}
	cout << A << " " << B << endl;
}