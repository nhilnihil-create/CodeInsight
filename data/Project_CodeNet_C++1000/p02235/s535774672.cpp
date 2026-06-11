#include <iostream>
#include <string>
using namespace std;

int main() {
	int setN;
	cin >> setN;
	string A,B;

	for (int i=0;i<setN;i++) {
		cin >> A;
		cin >> B;
		int L[2000][2000] ={};

		for(int j=1;j<A.length()+1;j++) {
			for(int l=1;l<B.length()+1;l++) {
				if(A[j-1] == B[l-1]) {
					L[j][l] = 1+L[j-1][l-1];

				} else {
					L[j][l] = max(L[j-1][l],L[j][l-1]);
				}
				
			}
		}
		/*
		for(int j=0;j<A.length()+1;j++) {
			cout << endl;
			for(int l=0;l<B.length()+1;l++) {
				cout << L[j][l] << " ";
				
			}
		}
		*/

		cout << L[A.length()][B.length()] << endl;


	}
}