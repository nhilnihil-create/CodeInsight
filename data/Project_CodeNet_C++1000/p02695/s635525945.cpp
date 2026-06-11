#include<iostream>

using namespace std;

int main(){
	int N, M, Q;
	int abcd[50][4];
	int A[10];
	bool flag = false;
	int maxpoint = 0;
	int nowmaxpoint = 0;

	cin >> N >> M >> Q;

	for(int i = 0; i < Q; ++i){
		cin >> abcd[i][0] >> abcd[i][1] >> abcd[i][2] >> abcd[i][3];
	}

	for(int j = 0; j < N; ++j){
		A[j] = 1;
	}

	while(!flag){
		for(int k = 0; k < Q; ++k){
			if(A[abcd[k][1] - 1] - A[abcd[k][0] - 1] == abcd[k][2]){
				maxpoint += abcd[k][3];
			}
		}

		// 最大値更新
		if(maxpoint > nowmaxpoint){
			nowmaxpoint = maxpoint;
		}

		//数列更新 末尾から
		if(A[N-1] < M){
			++A[N-1];
		}else if(N-2 >= 0 &&
			 A[N-2] < A[N-1]){
				 ++A[N-2];
				 A[N-1] = A[N-2];
		}else if(N-3 >= 0 &&
			A[N-3] < A[N-2]){
				++A[N-3];
				A[N-2] = A[N-3];
				A[N-1] = A[N-3];
		}else if(N-4 >= 0 &&
			A[N-4] < A[N-3]){
				++A[N-4];
				A[N-3] = A[N-4];
				A[N-2] = A[N-4];
				A[N-1] = A[N-4];
		}else if(N-5 >= 0 &&
			A[N-5] < A[N-4]){
				++A[N-5];
				A[N-4] = A[N-5];
				A[N-3] = A[N-5];
				A[N-2] = A[N-5];
				A[N-1] = A[N-5];
		}else if(N-6 >= 0 &&
			A[N-6] < A[N-5]){
				++A[N-6];
				A[N-5] = A[N-6];
				A[N-4] = A[N-6];
				A[N-3] = A[N-6];
				A[N-2] = A[N-6];
				A[N-1] = A[N-6];
		}else if(N-7 >= 0 &&
			A[N-7] < A[N-6]){
				++A[N-7];
				A[N-6] = A[N-7];
				A[N-5] = A[N-7];
				A[N-4] = A[N-7];
				A[N-3] = A[N-7];
				A[N-2] = A[N-7];
				A[N-1] = A[N-7];
		}else if(N-8 >= 0 &&
			A[N-8] < A[N-7]){
				++A[N-8];
				A[N-7] = A[N-8];
				A[N-6] = A[N-8];
				A[N-5] = A[N-8];
				A[N-4] = A[N-8];
				A[N-3] = A[N-8];
				A[N-2] = A[N-8];
				A[N-1] = A[N-8];
		}else if(N-9 >= 0 &&
			A[N-9] < A[N-8]){
				++A[N-9];
				A[N-8] = A[N-9];
				A[N-7] = A[N-9];
				A[N-6] = A[N-9];
				A[N-5] = A[N-9];
				A[N-4] = A[N-9];
				A[N-3] = A[N-9];
				A[N-2] = A[N-9];
				A[N-1] = A[N-9];
		}else if(N-10 >= 0 &&
			A[N-10] < A[N-9]){
				++A[N-10];
				A[N-9] = A[N-10];
				A[N-8] = A[N-10];
				A[N-7] = A[N-10];
				A[N-6] = A[N-10];
				A[N-5] = A[N-10];
				A[N-4] = A[N-10];
				A[N-3] = A[N-10];
				A[N-2] = A[N-10];
				A[N-1] = A[N-10];
		}else{
			flag = true;
		}
		maxpoint = 0;
	}

	cout << nowmaxpoint << endl;

}