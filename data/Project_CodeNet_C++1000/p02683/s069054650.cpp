#include <bits/stdc++.h>

using namespace std;



int main(void)
{
	int N, M, X;
	long long ans, minCost = INTMAX_MAX;
	bool ansFlag = false;

	cin >> N >> M >> X;

	vector<int> C(N, 0), tmpV(M, 0), x(M, 0);
	vector<vector<int>> A(N, tmpV);

	for (int i = 0; i < N; i++) {
		cin >> C[i];
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	for (int bit = 0; bit < (1 << N); bit++) {
		ans = 0;
		x = tmpV;

		for (int i = 0; i < N; i++) {
			if (bit & (1 << i)) {
				ans = ans + C[i];
				for (int j = 0; j < M; j++) {
					x[j] += A[i][j];
				}
			}
		}
		 ansFlag=true;
		for (int i = 0; i < M; i++) {
			if (x[i] < X) {
				ansFlag=false;
				break;
			}
		}

		if ( (minCost > ans)  && (ansFlag)) {
			minCost = ans;
		}
	}

	if(minCost < INTMAX_MAX){
		cout << minCost << endl;
	}else{
		cout<<-1<<endl;
	}


	


	return 0;
}
