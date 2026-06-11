#include <iostream>
using namespace std;

int main(){
	int N,M,P;

	while(1){
		cin >> N >> M >> P;
		if ((N == 0)&&(M == 0)&&(P == 0)){
			break;
		}

		double A[N];
		double sum = 0;
		double num = 0;
		double money;
		for (int i = 1; i <= N; i++){
			cin >> A[i];
			sum += A[i]*100;
			if (i == M){
				num = A[i];
			}
		}
		
		money = (sum*(100 - P)/100)/num;
		//cout << M << " " << num << " " << sum << " " << money << " " << P << endl;

		if (num == 0){
			cout << 0 << endl;
		} 
	else if (num != 0){
		cout << (int)money << endl;
	 }
	}
}