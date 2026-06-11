#include <iostream>
using namespace std;

int main(){
	int r,c;
	int A[101][101];
	cin >> r >> c;

	for(int i=0; i<=r; i++){  
		for(int j=0; j<=c; j++){
			A[i][j]=0;
		}
	}

	
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			cin >> A[i][j];
			A[i][c] += A[i][j];
			A[r][j] += A[i][j];
			A[r][c] += A[i][j];
		}
	}


	for (int i = 0; i<=r; i++) {
        for (int j = 0; j<c; j++) {
            cout << A[i][j] << ' ';
        }
		cout << A[i][c] << "\n";
    }

	return 0;
}